# Bài 1: Tìm hiểu các phương pháp mã hóa cổ điển
## 1. Caesar
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
### Mã hóa & giải mã
- Bằng Code C++:
<p align="center"><img width="695" height="312" alt="Ảnh chụp màn hình 2025-09-26 153343" src="https://github.com/user-attachments/assets/1e9d1655-4811-4bde-94f3-4862d926c486" /> </p>
- Mã hóa bằng HTML:
<p align="center"> <img width="579" height="472" alt="Ảnh chụp màn hình 2025-09-26 155005" src="https://github.com/user-attachments/assets/1edc5e6c-0fce-4480-b84b-a40ac7b5dea9" />
</p>
- Giải mã bằng HTML:
<p align="center"> <img width="576" height="473" alt="Ảnh chụp màn hình 2025-09-26 155155" src="https://github.com/user-attachments/assets/9e4d4342-f819-499f-b2d8-bb640085a213" /> </p>

## 2. Affine
### Tên: Affine cipher (mã tuyến tính-affine)
### Thuât toán:
- Mã hoá sử dụng hai tham số (a, b) với a phải nguyên tố cùng nhau với 26 (gcd(a,26)=1)
- Với chữ được ánh xạ thành số x ∈ {0..25}:
  - Mã hoá: E(x) = (a * x + b) mod 26
  - Giải mã: D(y) = a^{-1} * (y - b) mod 26, trong đó a^{-1} là nghịch đảo modulo 26 (số a_inv sao cho a * a_inv ≡ 1 (mod 26))
- Ví dụ: a=5, b=8 → E(x) = (5x+8) mod 26
### Không gian khóa:
- a có thể chọn từ tập các số coprime với 26: {1,3,5,7,9,11,15,17,19,21,23,25} — 12 khả năng
- b có 26 giá trị (0..25)
- Tổng số khóa = 12 × 26 = 312
### Cách phá:
- Brute-force (thử mọi (a,b)): chỉ 312 khả năng → dễ dò
  - Thực hiện: lặp mọi a trong 12 giá trị, mỗi b trong 0..25, giải mã và kiểm tra plaintext hợp lý
- Phân tích tần suất: Affine là ánh xạ tuyến tính — tần suất chữ cái biến đổi dựa trên affine; nếu có lượng lớn dữ liệu, phân tích tần suất có thể giúp tìm a và b
- Quy trình tấn công (brute-force):
  - Lấy ciphertext
  - Với mỗi a trong tập hợp cho phép, hãy tính a_inv. Với mỗi b trong 0..25: tính ứng viên văn bản thuần túy a_inv*(yb) mod 26
  - Kiểm tra bằng từ điển/ngôn ngữ, chọn candidate hợp lý
### Mã hóa & giải mã
- Bằng code C++:
<p align="center"> <img width="689" height="315" alt="Ảnh chụp màn hình 2025-09-26 160224" src="https://github.com/user-attachments/assets/0e3c8f23-40f1-43e4-827e-84437dc1c331" /> </p>
- Mã hóa bằng HTML : 
<p align="center"> <img width="574" height="540" alt="Ảnh chụp màn hình 2025-09-26 160854" src="https://github.com/user-attachments/assets/23404b31-fd81-4ee4-a7b6-b8d730cc4c61" /> </p>
- Giải mã bằng HTML:
<p align="center"> <img width="578" height="543" alt="Ảnh chụp màn hình 2025-09-26 161125" src="https://github.com/user-attachments/assets/57487dd6-a4c8-40ec-8dbf-269d8a9081b8" /> </p>





