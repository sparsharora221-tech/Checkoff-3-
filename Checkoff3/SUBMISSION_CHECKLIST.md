# Checkoff 3 — 5 PM, SN 135 — Final Submission Checklist

## Immediately

- [ ] Verify your registered subtopic is **Run-Length Encoding**, and no one in the same session has it. If not, this package needs adaptation to your registered topic.
- [ ] Confirm the professor's latest slide/AI policy; the uploaded PDF still says "Your slides should not be AI-generated." Review and personalize all slides, especially the explanations, design, and any ownership statements.
- [ ] Open `slides/Checkoff3_RLE_Presentation.pptx` in PowerPoint or Google Slides and add your name; adjust it so you can explain each slide in your own words.
- [ ] Run `make && make test` in the project folder. Try `./rle ABCDEF` and `./rle AAAAABBBCCDAA` yourself.

## Before your scheduled in-person checkoff

- [ ] Practice the 5–7 minute talk using `presentation/6_minute_speaker_script.md`.
- [ ] Ask the audience to predict the outcome on Slide 6 and pause for an answer.
- [ ] Record **yourself** presenting with the same slides and material; check audio and that the entire talk is recorded.
- [ ] Submit the prerecorded video **before** your presentation. The PDF does not name the submission platform; use your course portal's instructions.
- [ ] Create a **public** GitHub repository, upload your personalized README, code, tests, slides, and resources. Verify its public URL opens when logged out.
- [ ] Complete the reflection with 2–3 *real* AI prompts, what you learned/tested, what you would change, and a real conversation permalink; submit it in the designated course portal.

## In person

- [ ] Arrive on time, with the presentation ready and accessible offline.
- [ ] Speak for **5–7 minutes**, then handle ~3 minutes of questions.
- [ ] Give classmates time to answer your audience question.
- [ ] Ask at least one question **after each classmate's** presentation.

## GitHub commands (if you have Git configured)

From the extracted project directory, after you create an empty **public** repository on GitHub:

```bash
make clean
# Open your downloaded project folder in the terminal first.
git init
git add .
git commit -m "Add checkoff 3 RLE exploration"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
git push -u origin main
```

Replace the URL with the one GitHub actually shows. Do **not** paste a guessed remote URL.

## If time runs short, prioritize

1. Confirm the subtopic and review/customize slides.
2. Record and submit the full video *before* the slot.
3. Create a public GitHub repo with the required files.
4. Submit an honest, personalized reflection and conversation permalink.
5. Rehearse aloud once and prepare to ask classmates questions.
