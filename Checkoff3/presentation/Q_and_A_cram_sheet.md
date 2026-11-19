# 3-Minute Q&A Preparation

## Be able to answer these in 1–3 sentences

**Q1: What is RLE?**
A lossless encoding technique that represents a consecutive run of repeated values with its length and the repeated value. Example: `AAAAA` becomes `5A` in our teaching format.

**Q2: Why is it called lossless?**
The decoder uses each count and symbol to reconstruct the exact original sequence. No input characters are discarded.

**Q3: Does it always make data smaller?**
No. `ABCDEF` has no repeats, so our encoding becomes `1A1B1C1D1E1F`: 6 characters becomes 12. Real implementations may choose alternative encodings for non-repeating parts.

**Q4: What is a 'run'?**
A consecutive sequence of identical symbols. `AABAA` contains three runs: `AA`, `B`, and `AA`; the two A runs cannot be merged because they aren't adjacent.

**Q5: How do you decompress `4B2W`?**
Write `BBBB` and then `WW`, producing `BBBBWW`.

**Q6: Why use C for the demo?**
It connects directly to COMP 211 concepts such as character arrays, indexing, loops, `strlen`, `malloc`, and checking memory allocations. The algorithm itself works in many languages.

**Q7: What if there are 12 repeated A characters?**
The teaching format writes `12A`. The decoder reads all consecutive digits as the run count, then reads the letter. This is one reason the demonstration only accepts letters A–Z.

**Q8: Can the demo encode numbers and punctuation?**
Not as written: it intentionally rejects them. General-purpose RLE needs a carefully designed format for all possible bytes, such as fixed-size runs, escape markers, or binary run-length records.

**Q9: What's the difference between RLE and ZIP?**
RLE only compresses adjacent repetitions. General-purpose ZIP formats use more powerful techniques that can exploit other kinds of redundancy, including patterns that repeat in different locations.

**Q10: How can you test that your algorithm works?**
Encode, decode, and compare the result to the original. Also test repetitive strings, strings with no repetitions, long runs, empty strings, and invalid input.

**Q11: Does RLE compress photos well?**
Usually not nearly as well as simple images with uniform areas: photographs frequently change colors from pixel to pixel, so runs may be short.

**Q12: What was your most surprising discovery?**
That a valid lossless compression method can *increase* file size. The example with six unique letters became twice as long in the simplified text format.

## What to ask classmates (required by rubric)

Pick an appropriate question *after each classmate presents*: "What was the most surprising limitation you discovered?" / "How could someone test whether that technique works well?" / "What would you explore next if you had another week?"

## What if you don't know the answer?

Say: "I focused my exploration on basic RLE and a C demonstration, so I haven't verified that implementation detail. My understanding is [brief, grounded explanation], and I'd check the format specification to confirm." This is better than guessing.
