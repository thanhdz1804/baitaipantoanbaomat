<img width="1614" height="866" alt="image" src="https://github.com/user-attachments/assets/b3c44c79-2d97-4bb3-871a-02295bf3fb66" />## BÀI TẬP MÔN: An toàn và bảo mật thông tin
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
<img width="1534" height="917" alt="image" src="https://github.com/user-attachments/assets/8a2e851d-2b95-454e-bfac-d3ec4eb6c706" />
<img width="1540" height="835" alt="image" src="https://github.com/user-attachments/assets/434675d1-5a62-4e21-bcab-0fe934b18e49" />

## Hoán vị
1.Tên gọi
Mã Hoán Vị (Permutation Cipher), còn gọi là Mã Chuyển Vị (Transposition Cipher), là phương pháp sắp xếp lại vị trí các chữ cái theo một quy tắc dựa trên khóa.
2. Thuật toán mã hóa, giải mã thuật toán
Thuật toán mã hoá
Một biến thể phổ biến là Columnar Transposition: Sắp văn bản rõ thành ma trận theo cột với chiều rộng bằng độ dài khóa (khóa là số cột hoặc thứ tự hoán vị). Sau đó đọc theo thứ tự cột dựa trên hoán vị của khóa.
Ví dụ: Khóa "3142" (hoán vị cột 3,1,4,2). Đổ plaintext vào ma trận theo hàng, đọc theo cột theo thứ tự khóa.
Thuật toán giải mã
Xây dựng ma trận theo thứ tự cột từ ciphertext (theo hoán vị khóa), sau đó đọc theo hàng để lấy plaintext.
3.Không gian khóa
Với khóa là hoán vị của n phần tử (n là độ dài khóa), không gian là n! (giai thừa n). Ví dụ, n=5 → 120 khóa.
4. Cách giải mã (mà không cần khóa)
Anagramming: Sắp xếp lại các nhóm chữ cái để tìm từ có ý nghĩa, đặc biệt với ciphertext ngắn.
Phân tích độ dài và tần suất: Ước lượng độ dài khóa bằng cách tìm chu kỳ lặp tần suất, sau đó thử các hoán vị.
Known plaintext attack: So sánh với plaintext đã biết để suy ra hoán vị.
5. Cài đặt mã hóa và giải mã thuật toán bằng code C++ và bằng html+css+javascript
## KẾT QUẢ
<img width="1536" height="889" alt="image" src="https://github.com/user-attachments/assets/8ff65191-1d7a-4c88-9af4-34f595225c57" />\
<img width="1765" height="851" alt="image" src="https://github.com/user-attachments/assets/4d21e637-48bd-4d5e-9366-df4414f26382" />

## Vigenère
1.Tên gọi
Mã Vigenère (Vigenère Cipher) là mã thay thế polyalphabetic, sử dụng khóa lặp lại để dịch chuyển từng chữ cái.
2. Thuật toán mã hóa, giải mã thuật toán
Thuật toán mã hoá
Khóa là từ khóa (ví dụ "KEY"), lặp lại để khớp độ dài plaintext. Với mỗi chữ cái plaintext x và khóa k_i (A=0, ...):
Chữ mã = (x + k_i) mod 26
Ví dụ: Plaintext "HELLO", khóa "KEY" lặp "KEYKE" → Ciphertext "RIJVS".
Thuật toán giải mã
Chữ rõ = (x - k_i) mod 26
3.Không gian khóa
Với khóa độ dài m, mỗi vị trí có 26 lựa chọn → 26^m. Nhưng thường m nhỏ, nên brute force khả thi nếu m biết.
4. Cách giải mã (mà không cần khóa)
asiski examination: Tìm chu kỳ lặp trong ciphertext để ước lượng độ dài khóa m (tìm khoảng cách giữa các chuỗi lặp).
Friedman test: Sử dụng chỉ số trùng hợp (Index of Coincidence) để đoán m.
Sau khi có m: Phân tích tần suất từng nhóm để đoán từng phần khóa như Caesar.
5. Cài đặt mã hóa và giải mã thuật toán bằng code C++ và bằng html+css+javascript
## KẾT QUẢ
<img width="1809" height="819" alt="image" src="https://github.com/user-attachments/assets/8d62fa43-a102-486c-9ce2-bd97624ac24a" />
<img width="1614" height="866" alt="image" src="https://github.com/user-attachments/assets/c23845fb-1322-4a37-8ed6-1e901b49ac6e" />

## Playfair Cipher
1. Tên gọi
Mã Playfair (Playfair Cipher) là mã thay thế digraph (xử lý cặp chữ cái), do Charles Wheatstone phát minh nhưng được đặt tên theo Lord Playfair.
2. Thuật toán mã hóa, giải mã thuật toán
Thuật toán mã hoá
Tạo ma trận 5x5 từ khóa (loại bỏ trùng lặp, kết hợp I/J, thêm chữ cái còn lại).
Plaintext chia thành cặp (thêm 'X' nếu lẻ, thay đôi trùng bằng 'X').
Đối với cặp (p1, p2):
Cùng hàng: Thay bằng chữ phải (vòng quanh).
Cùng cột: Thay bằng chữ dưới (vòng quanh).
Khác: Thay bằng chữ ở góc đối diện hình chữ nhật.
Ví dụ: Khóa "PLAYFAIR", plaintext "HELLO" → cặp HE LL O(X) → Ciphertext "DM NA GW".
Thuật toán giải mã
Tương tự nhưng dịch ngược: phải → trái, dưới → trên, góc đối diện giống.
3. Không gian khóa
Khóa là chuỗi chữ cái độc đáo, nhưng không gian lớn (khoảng 26! / (26- số chữ trong khóa)), thực tế brute force khó vì ma trận 5x5 có ~15e24 biến thể.
4. Cách phá mã (mà không cần khoá)
Phân tích tần suất digraph: Trong tiếng Anh, digraph phổ biến như TH, HE. So sánh với ciphertext.
Hill climbing hoặc genetic algorithm: Tối ưu hóa ma trận khóa để văn bản rõ có ý nghĩa.
Known plaintext attack: Sử dụng cặp đã biết để suy vị trí trong ma trận.
## KẾT QUẢ
<img width="1660" height="842" alt="image" src="https://github.com/user-attachments/assets/dc0c21b5-1412-48c4-bd6d-4ca0700a0b4a" />
<img width="1395" height="872" alt="image" src="https://github.com/user-attachments/assets/ce68151c-f5de-4bfe-a7a0-aa473746aa30" />



