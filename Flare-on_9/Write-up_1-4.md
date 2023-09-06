## Write-up flare-on 9
### Challenge 1-4
**1. Challenge 1: 01_flaredle**  
> * Đề bài cho chúng ta một file `01_flaredle.zip`, bên trong file zip có 4 file liên quan đến `js`  
~[img](img/chall1_1.png)  
> * Chúng ta sẽ thử mở file `index.html` xem giao diện của bài này là gì?  
~[img](img/chall1_2.png)  
> * Nhìn giao diện thì có lẽ bài muốn chúng ta nhập các kí tự trong bảng rồi **enter** để xác nhận. Vậy chúng ta sẽ xem bài này hoạt động như thế nào?  
> * Sau khi mở file **script.js** chúng ta đã thấy được file kiểm tra chính của bài này. Trong đó, hàm `checkGuess` chúng là hàm kiểm tra những gì chúng ta nhập vào ở trong giao diện.  
> * Chúng ta sẽ thấy một đoạn code so sánh ở trong hàm `checkGuess`. Nếu giá trị trong biến **guessString** (biến nhập vào) bằng với giá trị trong biến **rightguessString** thì sẽ in ra flag và ngược lại sẽ in ra thông báo sai.  
~[img](img/chall1_3.png)  
> * Giá trị trong biến **rightguessString** là giá trị được lấy trong file `word.js` được đính kèm cùng folder. Giá trị đó trỏ đến vị trí thứ 57 trong file `word.js`. Vậy chúng ta sẽ cùng xem giá trị đó cùng flag sẽ là gì?  
~[img](img/chall1_4.png)  
~[img](img/chall1_5.png)   
> * Sau khi tìm đến giá trị thứ 57 trong file `word.js` chúng ta đã thấy một chuỗi **flareonisallaboutcats**. Để đúng với flag của bài, chúng ta sẽ chỉ nối chuỗi đã tìm được với **@flare-on.com** là sẽ ra flag
>> ***Flag: flareonisallaboutcats@flare-on.com***  

**2. Challenge 2: 02_PixelPoker**  
> * Đề bài cũng cho chúng ta một file `02_PixelPoker.zip`, bên trong có một file **PixelPoker.exe** và một file **readme.txt**  
~[img](img/chall2_1.png)  
> * File **readme.txt** nhắc chúng ta cần chọn đúng điểm và click chính xác vào điểm đó. Có vẻ như nếu đúng thì sẽ in ra flag?  
~[img](img/chall2_2.png)
> * Vậy thì chúng ta sẽ thử mở chương trình lên để chọn thử vài điểm xem có đủ may mắn hay không? Và sau khi thử click vài lần thì chương trình sẽ hiện lên một thông báo **Womp womp...**.  
~[img](img/chall2_3.png)  
> * Chúng ta sẽ bắt đầu kiêm tra chuong trình để xem cơ chế hoạt động của nó và tìm ra điểm chính xác để có thể click vào và lấy flag.  
> * Đây là một chương trình GUI của windows, sau khi init cơ bản ban đầu cho map và các chuỗi thì chúng ta sẽ qua hàm **sub_401120** để làm gì đó? Chúng ta sẽ xem chức năng của hàm này.  
~[img](img/chall2_4.png)  
> * Hàm **sub_401120** sẽ đăng kí một cửa số được hiện lên trên màn hình, chức năng chính của cửa số được xử lí qua hàm **sub_4012C0**.
> * Sau khi nhìn một lượt qua hàm **sub_4012C0** chúng ta sẽ thấy có một đoạn dùng **strcmp** để so sánh với 2 giá trị. Trong đó có một giá trị có tên là **cy** nên sẽ nghi ngờ đây là tọa độ của điểm chúng ta cần click.
~[img](img/chall2_5.png)  
> * Trong hình trên, chúng ta sẽ thấy có 4 giá trị: 
>>> * **dword_412004 = 0x52414C46**  
>>> * **dword_412008 = 0x6E4F2D45**
>>> * **dword_413280 = cxx**
>>> * **cy**
> * Trong đó có 2 giá trị là **cxx** và **cy** là chưa có giá trị. Chúng ta sẽ lấy giá trị của 2 biến này bằng cách debug  
~[img](img/chall2_6.png)  
> * Sau khi lấy được 2 giá trị **cxx** và **cy**, chúng ta sẽ thực hiện phép chia đúng theo trong đoạn code để tìm ra tọa độ.  
~[img](img/chall2_7.png)
> * Chúng ta tìm được tọa độ cần click là `91,313`. Sau khi click đúng vào tọa độ đó thì flag sẽ được hiện ra.  
~[img](img/chall2_8.png)  
>> ***Flag: w1nN3r_W!NneR_cHick3n_d1nNer@flare-on.com***  

**3. Challeng 3: 03_magic8ball**
> * Đề bài cho chúng ta một file `03_magic8ball.zip`, bên trong có 1 file **Magic8Ball.exe** và khá nhiều file **.dll**  
~[img](img/chall3_1.png)  
> * Chúng ta sẽ xem file **.exe** kia sẽ làm gì? Đầu tiên chúng ta sẽ thực thi nó để xem nó trông như thế nào?  
> * Chuong trình sẽ nhận **các phím mũi tên** để lắc quả bóng, và chương trình cũng bắt chúng ta nhập vào một đoạn text rồi check.  
~[img](img/chall3_2.png)  
> * Chúng ta sẽ xem bên trong source code của file này và xem cách thức mà chương trình hoạt động như thế nào.
> * Ngay đầu vào chương trình sẽ call thằng đến file **sub_403690**. Trong hàm này, sau khi chương trình tự khởi tạo ở đầu hàm, chúng ta sẽ thấy một hàm có tên **sub_4027A0** được call để thực hiện gì đó?  
~[img](img/chall3_3.png)  
> * Hàm **sub_4012B0** được gọi đầu tiên, nhưng nó chỉ để lấy các chuỗi đã được khởi tạo sẵn nên không cần xem qua kĩ.  
~[img](img/chall3_4.png)  
> * Tiếp theo, chúng ta sẽ thấy hàm **sub_402090** được truyền vào khá nhiều biến. Hàm này có vẻ như sẽ copy thêm chuỗi vào biến đã được khởi tạo trước đó. Nhưng có một chuỗi khá khả nghi là: ***gimme flag pls?***. Chúng ta sẽ để ý thêm đến chuỗi này.  
~[img](img/chall3_5.png)  
> * Sau khi nhận event từ bàn phím bằng hàm **sub_401E50**, dữ liệu sẽ qua hàm **sub_4024E0**. Check trong hàm này sẽ thấy có một đoạn so sánh với chuỗi **gimme flag pls?**. Có vẻ như đoạn check ở bên trên gồm những kí tự **L**, **R**, **U**, **D** chính là thứ tự chúng ta cần nhấn các phím mũi thêm.
> * Sau khi check thì thứ tự đó sẽ là: **LLURULDUL**. Và sau đó nhập chuỗi **gimme flag pls?** để check. Đã có hướng làm, chúng ta sẽ thử để xem có may mắn hay không?  
> * Sau khi hoàn thành các bước trên, chúng ta đã có flag.  
~[img](img/chall3_6.png)  
>> ***Flag: aaa***  

**4. Challenge 4: 04_darn_mice**  
> * Bài cho chúng ta 1 file **darn_mice.exe**  
~[img](img/chall4_1.png)  
> * Sau khi load file vào IDA, chúng ta sẽ thấy file nhận vào thêm 1 đối số nữa, có lẽ đây là chuỗi cần truyền vào để lấy được flag hoặc cũng có thể chuỗi này là flag. Chuỗi này được truyền vào hàm **sub_401000** để thực hiện chức năng của bài.  
~[img](img/chall4_2.png)  
> * Hàm này sau khi nhận đối số đã truyền vào, đối số sẽ được qua một đoạn code để encode và sau đó được truyền vào hàm **sub_401280** có lẽ để gen flag  
~[img](img/chall4_3.png)  
> * Trong đoạn encode kia chúng ta sẽ thấy một câu lệnh khá lạ **`v2(v2)`**, nó đang tự gọi đến chính nó sau khi nhận giá trị từ **agrument[i] + v5[i]**. Vậy ở đây, mỗi **byte(v2)** sẽ phải là một câu lệnh để nó có thể thực hiện đúng được chương trình của mình.  
> * Vậy có bao nhiêu câu lệnh mà khi nó chỉ có 1 byte mà vẫn hoạt động. Có lẽ chúng ta đang nghĩ đến 2 câu lệnh là **ret** và **nop**. Chúng ta sẽ thử decode bằng lệnh **nop** trước. Với opcode của **nop = 0x90**, chúng ta sẽ thử decode bằng python.  
~[img](img/chall4_4.png)  
> * Có vẻ như lệnh **nop** với **opcode = 0x90** không đúng. Chúng ta sẽ thử tiếp với lệnh **ret** voié **opcode = 0xC3**  
~[img](img/chall4_5.png)  
> * Lần này đã ra một đoạn plaintext, chúng ta sẽ thử truyền vào đối số của file xem có ra flag hay không?  
~[img](img/chall4_6.png)  
> * Và thế là chúng ta đã có flag cho bài này  
[script](script_solve/chall4.py)  
>> ***Flag: i_w0uld_l1k3_to_RETurn_this_joke@flare-on.com***  