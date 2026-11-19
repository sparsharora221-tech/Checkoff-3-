# COMP 211 Checkoff 3 — 6-minute script for the revised slides

**Topic:** Run-Length Encoding (RLE)  
**Use:** Speak naturally; do not read slide numbers aloud. Replace the name and adjust any first-person wording to what you actually did. Pause at the audience question.  
**Estimated time:** Approximately 6 minutes at a conversational pace, with a short audience pause.

## Slide 1 — Run-length encoding (0:00–0:40)

Hi everyone, I'm [your name], and today I'm talking about run-length encoding, or RLE. It's a pretty simple way of compressing data when the same thing repeats a lot.

So, look at the letters on the slide. There are thirteen characters here, but a bunch of them are repeated. The question is: can we write the exact same information using fewer characters? In this example, we actually can. And the nice thing about this method is that we don't lose any of the original information.

## Slide 2 — The idea: count repeats (0:40–1:20)

The basic idea is to count how many times a character appears in a row. Instead of writing five A's, we write five followed by A. That's really the main trick behind RLE.

It's called lossless compression because you can reverse it and get exactly what you started with. We're not throwing away any information. We're storing the same information in a different way.

One thing to remember is that it only counts characters that are right next to each other. It doesn't look through the whole string and combine every A into one group.

## Slide 3 — Encoding one string (1:20–2:10)

Let's go through our example from left to right. The first five characters are A's, so that becomes 5A. Three B's become 3B. Two C's become 2C. Then there's one D, so that's 1D. And the last two A's become 2A.

Putting those together gives us 5A3B2C1D2A. We went from thirteen characters to ten.

The easy thing to miss is the A's at the end. We can't combine them with the first five A's, because other letters are in between. Each separate group is called a run, and we have to keep the runs in the same order.

## Slide 4 — Decoding (2:10–2:45)

Okay, so how do we get the original string back? We just do the opposite. When we read 5A, we write A five times. 3B means three B's. 2C means two C's, and then we do the same thing with 1D and 2A.

When we finish, we get the exact original string back: AAAAABBBCCDAA. So even though we changed how the information was represented, none of it got lost. That's why this is an example of lossless compression.

## Slide 5 — I tried it in C (2:45–3:55)

I also have a small C program to show how this works. You don't need to follow every line, but the main idea uses two indexes: i and j.

i marks the start of the group we're counting. j moves forward for as long as the letters are the same. When the letter changes, j stops. So j minus i tells us how many of that letter we found.

Then printf prints the count followed by the letter, like 5A. We set i equal to j, and the next loop starts at the next group. We repeat that until the string ends.

This connects to COMP 211 because it's basically array indexing, while loops, and C strings. My full program also decodes the result and checks that the decoded text matches the original. I kept the demo to uppercase letters so the count format stays easy to understand.

## Slide 6 — Does it always compress? (3:55–4:45)

Now I want to ask a quick question. What if our input is ABCDEF, with no repeated letters at all? Do you think RLE makes it smaller, keeps it the same size, or makes it bigger?

[Pause about five seconds. Let someone answer.]

It's actually C—it gets bigger. Every letter needs its own count, so ABCDEF becomes 1A1B1C1D1E1F. We started with six characters, and now we have twelve.

So even though the method is called compression, it doesn't guarantee a smaller output. It works really well when there are long groups of repeats, but it can be a bad choice when the data changes constantly.

## Slide 7 — Where might this be useful? (4:45–5:30)

One place this can be useful is a simple black-and-white picture. Imagine the row of pixels shown here: four black pixels, then eight white pixels, then four black pixels again.

Instead of listing all sixteen pixels, we can write 4B8W4B. That describes the same pattern with fewer symbols. If a picture has lots of big solid areas, there can be long runs of identical pixels.

This is just a simplified example, though. Real image formats can have extra rules and much more complicated compression methods.

## Slide 8 — What I learned (5:30–6:05)

So here are the three things I'd want you to remember. First, RLE counts repeats that are next to each other. Second, it's lossless, so we can get the original data back exactly. And third, whether it saves space depends on the input. Sometimes the encoded version is actually bigger.

What I liked about this example is that a simple C loop demonstrates a real data-compression idea. And testing a bad example, not just the good one, shows us where the method falls short.

That's it from me. Thank you, and I'm happy to take questions.

---

**Delivery reminders:** Say the strings slowly, point at the groups on slide 3, pause for answers on slide 6, and use the code on slide 5 as a visual rather than reading each line aloud. If you are required to demonstrate the program live, run `./rle AAAAABBBCCDAA` and `./rle ABCDEF` after compiling.
