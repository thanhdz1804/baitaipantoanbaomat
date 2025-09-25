## BÀI TẬP MÔN: An toàn và bảo mật thông tin
# BÀI TẬP 1
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
1. Caesar
2.affine
3.Hoán vị
4. Vigenère
5.Hội chợ vui chơi
Với mỗi phương pháp, hãy tìm hiểu:
1.Tên gọi
2. Thuật toán mã hóa, giải mã thuật toán
3.Không gian khóa
4. Cách giải mã (mà không cần khóa)
5. Cài đặt mã hóa và giải mã thuật toán bằng code C++ và bằng html+css+javascript
### BÀI LÀM
##  Caesar
1. Tên gọi
Mã Caesar (Caesar Cipher) là một phương pháp mã hóa thay thế đơn giản, được đặt tên theo Julius Caesar, người được cho là đã sử dụng nó để bảo vệ thông tin quân sự.
2. Thuật toán mã hóa, giải mã thuật toán
- Thuật toán mã hóa Caesar hoạt động bằng cách dịch chuyển mỗi chữ cái trong văn bản rõ (plaintext) một số vị trí cố định trong bảng chữ cái. Giả sử bảng chữ cái tiếng Anh (A-Z), khóa k là số dịch chuyển (0-25). Công thức cho chữ cái thứ x (với A=0, B=1, ..., Z=25):
Chữ mã (ciphertext) = (x + k) mod 26
Chỉ áp dụng cho chữ cái, giữ nguyên các ký tự khác (như khoảng trắng, dấu câu).
Ví dụ: Với k=3, "HELLO" trở thành "KHOOR".
- Thuật toán giải mã
Giải mã bằng cách dịch chuyển ngược lại:
Chữ rõ = (x - k) mod 26 (với x là chữ mã).
Ví dụ: Với k=3, "KHOOR" trở lại "HELLO".
3.Không gian khóa
  Không gian khóa là 26 (từ 0 đến 25), vì dịch chuyển quá 25 sẽ lặp lại (mod 26). Khóa 0 là trường hợp đặc biệt (không mã hóa).
4. Cách giải mã (mà không cần khóa)
  Brute force: Thử tất cả 26 khóa có thể và kiểm tra văn bản rõ có ý nghĩa (rất nhanh vì không gian khóa nhỏ).
Phân tích tần suất: Trong tiếng Anh, chữ cái phổ biến như E (12.7%), T (9%), A (8%). So sánh tần suất trong ciphertext với bảng chuẩn để đoán k.
5. Cài đặt mã hóa và giải mã thuật toán bằng code C++ và bằng html+css+javascript
## KẾT QUẢ
<img width="1871" height="861" alt="image" src="https://github.com/user-attachments/assets/a0c081c9-afdf-486d-8329-52811e7e780f" />
<img width="1869" height="809" alt="image" src="https://github.com/user-attachments/assets/3291481b-aabf-4afe-81ae-6c86e006c0e1" />

## Affine
1.Tên gọi
Mã Affine (Affine Cipher) là một loại mã thay thế monoalphabetic, mở rộng từ mã Caesar bằng cách sử dụng phép nhân và cộng modulo
2. Thuật toán mã hóa, giải mã thuật toán
Thuật toán mã hoá
Sử dụng khóa (a, b) nơi a là số nguyên tố cùng nhau với 26 (gcd(a, 26)=1), b là số từ 0-25. Với x là vị trí chữ cái (A=0, ..., Z=25):
Chữ mã = (a * x + b) mod 26
Chỉ áp dụng cho chữ cái.
Ví dụ: Với a=5, b=8, "HELLO" (7,4,11,11,14) trở thành "RCLLA".
Thuật toán giải mã
Tìm nghịch đảo modular của a modulo 26 (a_inv sao cho (a * a_inv) mod 26 = 1). Sau đó:
Chữ rõ = a_inv * (x - b) mod 26
Ví dụ: Với a=5 (a_inv=21), b=8, "RCLLA" trở lại "HELLO".
3.Không gian khóa
Không gian khóa là số cặp (a, b) hợp lệ: Có 12 giá trị a (coprime với 26: 1,3,5,7,9,11,15,17,19,21,23,25), mỗi a có 26 b → Tổng 12 * 26 = 312.
4. Cách giải mã (mà không cần khóa)
Brute force: Thử tất cả 312 khóa và kiểm tra văn bản rõ có ý nghĩa.
Phân tích tần suất: So sánh tần suất chữ cái trong ciphertext với bảng chuẩn (E phổ biến nhất), giải hệ phương trình để tìm a và b từ hai cặp chữ cái phổ biến.
Known plaintext attack: Nếu biết một phần plaintext, giải hệ để tìm a, b.
5. Cài đặt mã hóa và giải mã thuật toán bằng code C++ và bằng html+css+javascript
## KẾT QUẢ
