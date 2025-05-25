# 🔐 RSA Encryption-Decryption with Auto-Correction in C

This project is a **C language implementation** of the **RSA encryption and decryption algorithm** enhanced with **auto-correction** of decrypted messages using the **Levenshtein Distance algorithm**. The project makes extensive use of **data structures** such as linked lists and hash tables for managing data efficiently.

---

## 📌 Project Overview

The objective of this project is to:
- Securely **encrypt** and **decrypt** messages using **RSA**.
- Apply **Levenshtein distance** to correct words in the decrypted message that may have been corrupted or altered.
- Use **data structures** to manage keys, words, and dictionary for correction.

---

## 🔐 RSA Algorithm

RSA is a widely-used **asymmetric encryption** algorithm that uses a **public key** for encryption and a **private key** for decryption.

### ✔️ Key Steps
1. **Key Generation**
   - Generate two large prime numbers `p` and `q`
   - Compute `n = p × q`
   - Compute Euler's totient `φ(n) = (p-1)(q-1)`
   - Choose encryption key `e` (1 < e < φ(n), and gcd(e, φ(n)) = 1)
   - Compute decryption key `d` such that `d ≡ e⁻¹ mod φ(n)`

2. **Encryption**
   - Convert each character of the message to its ASCII value
   - Apply: `cipher = (message^e) mod n`

3. **Decryption**
   - Apply: `message = (cipher^d) mod n`
   - Convert numerical values back to characters

---

## 🔁 Auto-Correction with Levenshtein Distance

After decryption, the message may contain errors. To correct these:
- A **dictionary** is used for reference
- Each word is compared against the dictionary
- The **Levenshtein distance** is calculated to find the closest match
- If the distance is within a threshold (e.g. ≤ 2), the word is corrected

---


---

## 🛠️ Tools & Technologies

| Component        | Description               |
|------------------|---------------------------|
| **Language**     | C                         |
| **Compiler**     | GCC                       |
| **Libraries**    | `<math.h>`, `<string.h>`, custom DS |
| **Levenshtein**  | Custom implementation     |

---


