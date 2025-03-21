/*
Hai thuộc tính quan trọng của bảng băm là:
1. Phân bố đèu
Hàm băm nên phân bố các khóa một cách đồng đều trên bảng băm để tránh tình trạng các vị trí bị quá tải (collision quá nhiều).
Nếu các khóa bị dồn vào một số ít vị trí, hiệu suất tìm kiếm sẽ giảm đi đáng kể.
VD: Min, Max
2. Tính toán nhanh
Hàm băm cần được thiết kế sao cho có thể tính toán giá trị băm một cách nhanh chóng.
Điều này giúp các thao tác tìm kiếm, chèn, hoặc xóa phần tử diễn ra hiệu quả, đặc biệt quan trọng đối với các ứng dụng thời gian thực hoặc khi có lượng dữ liệu lớn.
*/