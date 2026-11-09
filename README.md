# Base-N Converter with a Twist

## Problem Statement
The objective of this assignment is to generalize the binary conversion concept (from Listing 9.8) into a flexible `to_base_n()` function that accepts any decimal integer and converts it to a target base between 2 and 16. Additionally, the program must implement a **Custom Alphabet Rule** for remainders 10 through 15 (`!`, `@`, `#`, `$`, `%`, `^`) instead of standard alphabetical characters, along with specific prefix formatting rules for octal (`0`) and hexadecimal (`0x`) outputs.

## Describe the Solution
- **Recursive Conversion (`to_base_n`):** The program uses recursion to extract digits from least significant to most significant by repeatedly dividing the number by the target base and taking the remainder.
- **Custom Character Mapping:** An array `char custom_alphabet[] = "0123456789!@#$%^";` maps numeric remainders (0–15) directly to their respective ASCII representations, satisfying the custom symbol requirement seamlessly.
- **Error Handling & Formatting:** Input bases outside the 2–16 range trigger an explicit error message. Conditional checks in `main()` automatically prepend `0` for base 8 and `0x` for base 16 to meet the output specification.

## Pros and Cons of your solution
### Pros:
- **Clean and Concise:** Recursion keeps the code compact and naturally prints digits in the correct left-to-right order without needing explicit reversal arrays or stacks.
- **Extensible:** The custom alphabet array approach makes it easy to modify or expand symbol mappings if needed.
- **Robust Validation:** Guard clauses prevent invalid bases from executing calculations or causing undefined behavior.

### Cons:
- **Recursion Depth:** For extremely large numbers, deep recursion could potentially risk stack overflow, though well within safe limits for standard integer inputs.
- **Limited Input Validation:** Non-numeric inputs during `scanf` prompts require careful user handling to avoid infinite loops.
