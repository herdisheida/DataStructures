#!/bin/bash

if [ ! -f "./program" ]; then
    echo "No program found in this folder. Run make first."
    exit 1
fi

failed=0

for f in tests/*.in; do
    ./program < "$f" > out.tmp
    expected="${f%.in}.out"
    
    if diff -q "$expected" out.tmp > /dev/null; then
        echo "PASS - $f"
    else
        echo "FAIL - $f"
        # echo "-------------------------------"
        # printf "%-30s | %s\n" "$expected" "YOUR OUTPUT"
        # echo "-------------------------------"
        # diff -y --width=70 --color "$expected" out.tmp
        # echo "-------------------------------"
        failed=$((failed + 1))
    fi
done
rm -f out.tmp


echo ""
if [ $failed -eq 0 ]; then
    echo "All tests passed!"
else
    echo "$failed test(s) failed."
fi