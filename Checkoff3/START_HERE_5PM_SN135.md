# Your Checkoff 3 — 5:00 PM, SN 135

## Download-and-submit roadmap

1. **Confirm topic:** This kit is about **Run-Length Encoding (RLE)**. It only matches your signup if RLE is your registered subtopic. The signup screenshot established your time/location, but you must verify the topic.
2. **Slides:** Open `slides/Checkoff3_RLE_Presentation.pptx`; add your name on Slide 1; read each slide and correct/customize it to match your own understanding. A PDF copy is included as a backup. Your uploaded instructions prohibit AI-generated slides; do not submit this generated draft as your own if that rule still applies. You mentioned a newer policy: confirm it permits this.
3. **Practice:** Use `presentation/6_minute_speaker_script.md` to rehearse a 5–7 minute explanation. Do not read the slides word-for-word. Ask your classmates the prediction question on Slide 6.
4. **Code:** From the extracted kit directory, run `make && make test`; run `./rle` and `./rle ABCDEF` and understand both outputs.
5. **Video:** Record yourself presenting all 8 slides in a ~6 minute video, verify audio, submit before the in-person checkoff using your course portal.
6. **GitHub:** Create a public repo and upload README, `src/`, `tests/`, Makefile, `slides/`, `presentation/`, and references. The repo must be publicly accessible. The README has a complete explanation and source links.
7. **Reflection:** Update `reflection/reflection_template.md` with 2–3 prompts you *actually used*, what you personally learned and tested, and your chat share URL. Submit it through the appropriate portal.
8. **In person:** Be in **SN 135 by 5:00 PM** with slides ready offline. Speak 5–7 minutes, answer questions for about 3 minutes, ask one audience prediction question, and ask a question following each classmate's talk.

## Quick demo

```bash
make
make test
./rle AAAAABBBCCDAA
./rle ABCDEF
```

Expected key lines:

```
AAAAABBBCCDAA -> 5A3B2C1D2A; 13 -> 10 characters
ABCDEF -> 1A1B1C1D1E1F; 6 -> 12 characters
```

## Slide pacing (target 6:20 total)

1. Hook 0:40
2. Compression 0:45
3. Encoding 0:50
4. Decoding 0:40
5. C algorithm 1:00
6. Audience question & limitation 0:50
7. Image example 0:50
8. Takeaway 0:45

## If you are running short on time

The deadline-critical submissions are the prerecorded video **before your slot**, the public GitHub link, and the truthful reflection. Leave time to verify these actually submitted.
