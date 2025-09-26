# Bài 1: Tìm hiểu các phương pháp mã hóa cổ điển
## 1. caesar
### Tên: Caesar cipher (mã Caesar)
### Thuật toán: 
- Bảng chữ cái: A..Z (26 chữ)
- Mã hoá với khóa k (0 ≤ k ≤ 25):
  - Với ký tự chữ hoa X (số = 0..25): E(X) = (X + k) mod 26
  - Với ký tự chữ thường x: E(x) = (x + k) mod 26
- Giải mã: D(Y) = (Y - k + 26) mod 26
- Ví dụ: k=3, A → D, Z → C
### Không gian khóa: 
- Có 26 giá trị k (k = 0..25). Thường k=0 được coi là không mã hoá, nên số khóa hữu ích là 25
### Cách phá:
- Brute-force (thử mọi khóa) — dễ nhất: thử k từ 1..25, cho ra 25 bản có thể đọc được bằng mắt
  - Phức tạp: O(26) — rất nhỏ
- Phân tích tần suất — với văn bản dài, chữ E (tiếng Anh) xuất hiện nhiều, so sánh chuỗi mật với tần suất tiếng thường để suy k
- Quy trình tấn công (brute-force):
  - Lấy ciphertext
  - Với mỗi k từ 1..25, dịch ngược và tạo candidate plaintext
  - Dùng nhận diện ngôn ngữ (kiểm tra từ khoá tiếng Việt/tiếng Anh, tỷ lệ chữ cái hợp lệ) để chọn bản đúng
