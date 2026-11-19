# Checkoff 3 — Run-Length Encoding: 6-Minute Speaker Script

**How to use this:** Rehearse aloud once, personalize the opening and reflection, and then explain in your own words rather than reading every sentence. Timing is approximate. The speech below corresponds to slides 1–8 of the deck. The presenter is responsible for verifying that this is the registered checkoff subtopic.

## Slide 1 — Hook (0:00–0:40)

"Hi, I'm **[your name]**, and today I'll show you one simple trick computers use to store repeated information in less space. Look at these letters: `AAAAABBBCCDAA`. There are thirteen characters. If I told you we could represent that exact sequence using only ten characters, would you believe me? The trick is called **run-length encoding**, or RLE. I picked it because I know arrays and loops from COMP 211, and I wanted to see how those basic tools could solve a real data-storage problem."

## Slide 2 — What compression means (0:40–1:25)

"Compression means representing data in a way that needs less storage, at least when the data has patterns we can exploit. RLE is a form of **lossless compression**. Lossless means that after decompressing, we get exactly the same data back, with no letters or details missing. It's different from lossy compression, where some information can be discarded. RLE is especially simple: instead of writing the same symbol over and over, we keep a count and the symbol. It does not understand words or images; it only notices consecutive repetition."

## Slide 3 — How to encode a run (1:25–2:15)

"Let's encode our example one group at a time. We see five A's, so we write `5A`. Then three B's become `3B`. Two C's become `2C`. One D becomes `1D`. And the last two A's become `2A`. Put those together and you get `5A3B2C1D2A`. This example shrinks from thirteen characters to ten. Here's an important detail: the two A groups cannot be combined because they're separated by other letters. RLE compresses **adjacent runs**, not all occurrences of a symbol throughout the entire string."

## Slide 4 — Why it's lossless (2:15–2:55)

"How do we get the original information back? We reverse the instruction. `5A` means print A five times. `3B` means print B three times, and so on. After expanding every count-letter pair, the output is exactly `AAAAABBBCCDAA` again. That's what makes it lossless. For our simple demonstration, the input is restricted to uppercase A through Z. This avoids ambiguity when a number represents a count. A real file format needs a clearly specified encoding so it can also handle digits, punctuation, and arbitrary binary data."

## Slide 5 — A small C implementation (2:55–3:55)

"I tested the idea with a short C program. Here's the key loop. The index `i` marks the beginning of a run, and `j` moves forward while the letters are the same. The difference `j - i` tells us the length of that run. Then we output the count and the letter, and set `i = j` to start the next run. This relates to COMP 211 because it uses arrays, pointer-accessible strings, loops, and dynamic memory. The program also decodes the result and checks whether the recovered string exactly matches the original. So I didn't just trust the compression; I verified that it can be reversed."

## Slide 6 — Audience prediction and the surprising failure case (3:55–4:45)

"Here's my question for everyone: **If the input is `ABCDEF`, do you think RLE will make it smaller, the same size, or bigger?** [Pause 5 seconds and invite a response.] It actually gets bigger in our demonstration. Since every letter appears only once in a row, the encoded result is `1A1B1C1D1E1F`: twelve characters instead of six. The output is twice as long. This surprised me because I initially thought compression always made things smaller. RLE is useful when there are long runs; it can waste space when the input keeps changing."

## Slide 7 — Real-world connection (4:45–5:35)

"A good use case is a simple black-and-white image. Imagine one row of pixels that has four black pixels, eight white pixels, and four black pixels. Instead of writing sixteen pixel labels, we could describe that row as `4B8W4B`. In this simplified representation that's six characters rather than sixteen. If large areas have the same color, there are long runs, which makes the pattern very efficient. This is why the idea appears in educational demonstrations of image compression and in some image or document formats. The details of real-world formats can be more sophisticated than our toy example."

## Slide 8 — Takeaway and reflection (5:35–6:20)

"My biggest takeaway is that **compression depends on the structure of the data**. A technique can be great for one kind of input and terrible for another. I also learned something about how to explore an unfamiliar systems topic: start with one concrete example, implement a small version, test cases that should work, and also test a case that might break your assumption. With RLE, the most valuable test was the six different letters, because it showed a limitation rather than just success. If you remember one thing, remember: count consecutive repeats, and always check whether the encoded representation is actually smaller. Thank you! I'm happy to take questions."

**Expected duration:** ~6 minutes 20 seconds at a conversational pace with a short audience-response pause. Record one practice run and adjust to stay between 5 and 7 minutes.
