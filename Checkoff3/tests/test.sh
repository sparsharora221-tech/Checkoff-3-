#!/usr/bin/env bash
set -euo pipefail
check() {
    local input="$1" expected="$2" actual
    actual="$(./rle "$input" | sed -n 's/^Encoded:  *//p')"
    if [[ "$actual" != "$expected" ]]; then
        printf 'FAIL: input=%q expected=%q actual=%q\n' "$input" "$expected" "$actual" >&2
        exit 1
    fi
    ./rle "$input" | grep -q '^Round trip: PASS$'
    printf 'PASS: %-18s -> %s\n' "${input:-<empty>}" "${expected:-<empty>}"
}
check 'AAAAABBBCCDAA' '5A3B2C1D2A'
check 'ABCDEF' '1A1B1C1D1E1F'
check 'AAAAAAAAAAAA' '12A'
check 'BBBBWWWWWWWWBBBB' '4B8W4B'
check '' ''
if ./rle 'hello' >/dev/null 2>&1; then
    echo 'FAIL: lowercase should be rejected' >&2
    exit 1
fi
echo 'All teaching-demo tests passed.'
