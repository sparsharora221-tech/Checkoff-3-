# COMP 211 Checkoff 3 — Run-Length Encoding (RLE)

**Presenter:** Sparsh Arora  
**Topic:** Data Compression — Run-Length Encoding (RLE)

> This is a starter portfolio package. Personalize the slides, README, and reflection to reflect what you actually studied, demonstrated, and presented. Confirm RLE is your approved, unique subtopic.

## What I explored

Run-length encoding is a simple **lossless** representation of data with repeated consecutive symbols. Rather than writing `AAAAA`, the teaching format writes `5A`, meaning "five A characters." It can save space on data with many repeated values but can use *more* space on data with short or no runs.

Examples:

| Original | RLE encoding | Characters before → after | Result |
|---|---|---|---|
| `AAAAABBBCCDAA` | `5A3B2C1D2A` | 13 → 10 | 23.1% fewer characters |
| `ABCDEF` | `1A1B1C1D1E1F` | 6 → 12 | 100% expansion |
| `BBBBWWWWWWWWBBBB` | `4B8W4B` | 16 → 6 | 62.5% fewer characters |

These sizes are for our **simplified uppercase-letter text representation**, not a claim about a real binary file format or file headers.

## What I learned

- RLE works with **consecutive runs**, not all occurrences of a letter.
- Lossless encoding allows exact reconstruction of the original input.
- A compressor must be evaluated using both repetitive and nonrepetitive inputs.
- Coding in C connects the algorithm to loops, strings, `malloc`, `free`, and testing.

## Run the C demonstration

Requirements: GCC, Make, and a shell (Linux / macOS / course development container).

```bash
make
./rle
./rle ABCDEF
./rle BBBBWWWWWWWWBBBB
make test
```

The demonstration accepts uppercase letters `A` through `Z` only, to keep count/letter parsing unambiguous. It both **encodes and decodes** the data and reports whether decoding reproduces the exact original string. It is not a general-purpose file compressor.

### Example output

```text
Original: AAAAABBBCCDAA
Encoded:  5A3B2C1D2A
Decoded:  AAAAABBBCCDAA
Sizes:    13 -> 10 characters
Savings:  23.1% (negative means expansion)
Round trip: PASS
```

## Repository structure

- `src/rle.c` — educational RLE encoder/decoder in C
- `tests/test.sh` — automated test cases
- `Makefile` — build and test commands
- `slides/` — PowerPoint and PDF copies of presentation draft
- `presentation/` — speaker script and Q&A preparation
- `reflection/` — reflection template to personalize
- `SUBMISSION_CHECKLIST.md` — last-minute steps

## Sources and further reading

1. CS Unplugged, *Squeezing pictures into less space*: https://www.csunplugged.org/en/topics/image-representation/squeezing-pictures-into-less-space/
2. Computer Science Field Guide, *Run-length encoding*: https://www.csfieldguide.org.nz/en/chapters/coding-compression/run-length-encoding/
3. DSP Guide, *Run-Length Encoding*: https://www.dspguide.com/ch27/2.htm

## Limitation and extension

The toy format uses decimal counts followed by an uppercase letter, such as `12A`. To support arbitrary binary files, a real implementation needs an explicit byte-level encoding and rules for escaping/splitting run lengths.
