# Checkoff 3 — Written Reflection (personalize before submitting)

**Topic:** Run-Length Encoding (RLE)

## How I explored the topic

I began with the basic question of how repeated data can be represented using fewer characters. I used AI to get a beginner-friendly explanation of RLE and to connect the algorithm to COMP 211 concepts such as C strings, loops, and dynamically allocated memory. A useful example was encoding `AAAAABBBCCDAA` as `5A3B2C1D2A`. I also explored a case that *doesn't* compress well: `ABCDEF` becomes `1A1B1C1D1E1F` using this teaching format.

**Personalize this paragraph:** Describe what you yourself actually did. For example, if you ran `make test`, say so; if you only read the code, don't claim you tested it.

## Representative AI prompts

Only include prompts that actually appear in your AI conversation. This is a checklist with examples to ask in the conversation, NOT a claim that you already asked them:

1. "Explain run-length encoding at a COMP 211 C programming level, with a worked example."
2. "Why does RLE make ABCDEF longer? Show how encoding and decoding work step by step."
3. "Walk me through the run-counting loop in C and give me boundary cases to test."

**Replace the list above with 2–3 verbatim prompts from your actual conversation.** You can send these suggested questions to your AI conversation now if you want them to become authentic exploration prompts.

## What I checked and what surprised me

What surprised me most was that RLE is not guaranteed to save space. [Insert one result you personally observed, such as the output from `./rle ABCDEF` after running it.] The example helped me realize that algorithms need to be judged on different input patterns, not only on the best case.

## What I would do differently

Next time I would ask for both a successful example and a counterexample earlier. I would also verify the algorithm with more test strings and investigate a format that can represent digits and punctuation without ambiguity.

## AI conversation permalink

[PASTE THE REAL SHARE LINK FROM THIS CHAT HERE]

**Reminder:** The checkoff instructions request a real conversation permalink, 2–3 representative prompts, and honest discussion of your own exploration. Do not submit placeholders as though they are completed work.
