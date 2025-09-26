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

## 4. Vigenère
### Tên: Vigenère cipher
### Thuật toán:
- Khóa: chuỗi ký tự K độ dài m
- Quy tắc (với chữ cái 0..25):
  - Mã hoá: E_i = (P_i + K_{i mod m}) mod 26 (ở đây K_j là số 0..25 ứng với ký tự khóa)
  - Giải mã: P_i = (E_i - K_{i mod m} + 26) mod 26
- Vigenère có thể coi là xâu các Caesar cipher nối tiếp nhau, mỗi vị trí dịch theo ký tự khóa
### Không gian khóa:
- Nếu khóa độ dài m và mỗi ký tự có 26 khả năng → tổng 26^m khóa
  - Ví dụ: m=3 → 17,576; m=6 → ~308 triệu; m=10 → ~1.4e14
- Vì thế không gian tăng theo m; tuy nhiên, nếu khóa là từ có nghĩa thì không gian thực tế nhỏ hơn
### Cách phá:
- Kasiski Examination (Kasiski test): tìm các đoạn trùng lặp trong ciphertext và đo khoảng cách giữa các lần xuất hiện; gcd của các khoảng cách có thể cho độ dài khóa m
- Friedman Test (Index of Coincidence — IC): dùng IC để ước lượng độ dài khóa; IC cao (≈0.066 cho tiếng Anh) gợi ý văn bản không bị phân mảnh; IC thấp (≈0.038) là ngẫu nhiên; tính IC cho các phân lớp (chia ciphertext theo vị trí mod m) để ước lượng m
- Sau khi biết m: chia ciphertext thành m chuỗi (mỗi chuỗi chứa ký tự ở cùng offset mod m). Mỗi chuỗi là Caesar cipher — thực hiện phân tích tần suất để tìm dịch chuyển (k) cho mỗi chuỗi
- Quy trình tấn công (tóm tắt):
  - Dùng Kasiski hoặc Friedman để ước lượng các giá trị khả dĩ của m
  - Với từng m candidate: chia ciphertext thành m chuỗi; cho mỗi chuỗi áp dụng phân tích tần suất (so sánh với tần suất chuẩn) để tìm shift tối ưu → suy ra khóa
  - Dùng đánh giá ngôn ngữ (n-gram scoring) để chọn khóa tốt nhất
- Lưu ý: nếu khóa rất dài hoặc giống chuỗi ngẫu nhiên (one-time pad), tấn công trở nên không khả thi
### Mã hóa & giải mã
- Mã hóa bằng code C++:
<p align="center"> <img width="679" height="301" alt="Ảnh chụp màn hình 2025-09-26 170435" src="https://github.com/user-attachments/assets/e4763c20-d0de-4b2f-b5d1-8ca380dbf584" /> </p>
- Giải mã bằng code C++:
<p align="center"> <img width="683" height="314" alt="Ảnh chụp màn hình 2025-09-26 170502" src="https://github.com/user-attachments/assets/0bfe113d-fbdc-417c-8cdf-d2cbb4f99466" /> </p>
- Mã hóa bằng HTML:
<p align="center"> <img width="581" height="478" alt="Ảnh chụp màn hình 2025-09-26 165657" src="https://github.com/user-attachments/assets/e1c8a25d-55f5-43a3-8d46-b78342a3fa9d" /> </p>
- Giải mã bằng HTML:
<p align="center"> <img width="581" height="480" alt="Ảnh chụp màn hình 2025-09-26 165709" src="https://github.com/user-attachments/assets/70f09301-b5b7-4e94-ab54-fd6700a15b91" /> </p>







