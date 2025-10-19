# Buffer Overflow

A simple C program to  a basic stack based buffer overflow vulnerability.

## Files

*   `vulnerable.c`: The intentionally vulnerable program. Uses `strcpy()` unsafely.
*   `patched.c`: The fixed version. Uses `strncpy()` to prevent the overflow.

## How to Run

### Vulnerable Version

1.  **Compile:**
    ```bash
    gcc -o vulnerable vulnerable.c -fno-stack-protector
    ```
    > **Note:** The `-fno-stack-protector` flag is required. Modern compilers add "stack canaries" by default to prevent buffer overflows. This flag disables that protection for this test.

2.  **Run exploit:**
    ```bash
    # This overflows the buffer and bypasses the password check.
    ./vulnerable AAAAAAAAAAAAAAAAAAAAAAAA
    ```
    *Expected Output: `Access Granted!`*

### Patched Version

1.  **Compile:**
    ```bash
    gcc -o patched patched.c
    ```
2.  **Attempt exploit:**
    ```bash
    # The exploit is blocked.
    ./patched AAAAAAAAAAAAAAAAAAAAAAAA
    ```
    *Expected Output: `Access Denied.`*

---
This code is for educational and testing purposes only.
