
>> %Run upfirebase.py
Traceback (most recent call last):
  File "/usr/lib/python3.7/ast.py", line 35, in parse
    return compile(source, filename, mode, PyCF_ONLY_AST)
  File "/home/pi/upfirebase.py", line 1
    import pyrebase
    ^
IndentationError: unexpected indent

error: subprocess-exited-with-error
  
  × Preparing metadata (pyproject.toml) did not run successfully.
  │ exit code: 1
  ╰─> [6 lines of output]
      
      Cargo, the Rust package manager, is not installed or is not on PATH.
      This package requires Rust and Cargo to compile extensions. Install it through
      the system's package manager or via https://rustup.rs/
      
      Checking for Rust toolchain....
      [end of output]
  
  note: This error originates from a subprocess, and is likely not a problem with pip.
error: metadata-generation-failed

× Encountered error while generating package metadata.
╰─> See above for output.

note: This is an issue with the package mentioned above, not pip.
hint: See above for details.




Python 3.7.3 (/usr/bin/python3)
>>> %Run upfirebase.py
Traceback (most recent call last):
  File "/home/pi/upfirebase.py", line 1, in <module>
    import pyrebase  # Đảm bảo đã cài đặt thư viện pyrebase4
ModuleNotFoundError: No module named 'pyrebase'
>>> 

protobuf requires Python '>=3.7' but the running Python is 2.7.16


  import pyrebase
from sense_emu import SenseHat
import time
import numpy as np

# Cấu hình Firebase
config = {
  "apiKey": "AIzaSyAsnwEx69yMaihMVqwPN2bQp67hyFhhUes",
  "authDomain": "myduck-3194f.firebaseapp.com",
  "databaseURL": "https://myduck-3194f-default-rtdb.firebaseio.com",
  "projectId": "myduck-3194f",
  "storageBucket": "myduck-3194f.firebasestorage.app",
  "messagingSenderId": "783046841055",
  "appId": "1:783046841055:web:56ce2590d7d5b15ac44f6a",
  "measurementId": "G-3DP599NTFK"
};
}

# Khởi tạo Firebase và SenseHAT
firebase = pyrebase.initialize_app(config)
database = firebase.database()
sense = SenseHat()

# Biến toàn cục
n = 5  # Kích thước lịch sử mảng
history = [0] * n  # Khởi tạo mảng lịch sử
previous_T = 0  # Giá trị T trước đó
temperature_change_threshold = 1  # Ngưỡng thay đổi nhiệt độ (1 độ)

# Hàm đọc dữ liệu và tối ưu gửi
def push_optimized_data():
    global history, previous_T  # Sử dụng biến toàn cục
    while True:
        try:
            # Đọc nhiệt độ hiện tại từ SenseHAT
            current_temp = round(sense.get_temperature(), 2)

            # Tính trung bình của lịch sử
            mean_temp = np.mean(history)

            # Tính T_cập_nhật
            T_cap_nhat = round((current_temp + mean_temp) / 2, 2)

            # So sánh sự thay đổi nhiệt độ với ngưỡng
            if abs(current_temp - previous_T) > temperature_change_threshold:
                # Gửi dữ liệu lên Firebase
                sensor_data = {
                    "temperature": T_cap_nhat,
                    "timestamp": time.strftime("%Y-%m-%d %H:%M:%S")
                }
                database.child("OptimizedSensorData").set(sensor_data)
                print("Đã gửi dữ liệu lên Firebase:", sensor_data)

                # Lưu vào SQL hoặc xử lý thêm tại đây nếu cần
                previous_T = T_cap_nhat  # Cập nhật T

            # Cập nhật mảng lịch sử
            history.pop(0)  # Xóa phần tử đầu tiên
            history.append(current_temp)  # Thêm giá trị mới vào cuối

            # In mảng lịch sử ra màn hình
            print("Lịch sử nhiệt độ:", history)

            # Tạm dừng 5 giây
            time.sleep(5)

        except Exception as e:
            print("Lỗi xảy ra:", e)

# Chạy chương trình
if __name__ == "__main__":
    print("Bắt đầu gửi dữ liệu tối ưu lên Firebase...")
    try:
        push_optimized_data()
    except KeyboardInterrupt:
        print("Đã dừng chương trình!")




>>> %Run upfirebase.py
Traceback (most recent call last):
  File "/home/pi/upfirebase.py", line 1, in <module>
    import pyrebase  # Đảm bảo đã cài đặt thư viện pyrebase4
ModuleNotFoundError: No module named 'pyrebase'


  python3: can't open file 'upfirebase': [Errno 2] No such file or directory






import pyrebase

config = {
    "apiKey": "YOUR_API_KEY",
    "authDomain": "YOUR_AUTH_DOMAIN",
    "databaseURL": "YOUR_DATABASE_URL",
    "storageBucket": "YOUR_STORAGE_BUCKET"
}

firebase = pyrebase.initialize_app(config)
db = firebase.database()

# Thêm dữ liệu mẫu vào Firebase
data = {"name": "John", "age": 30}
db.child("users").push(data)

print("Dữ liệu đã được thêm vào Firebase!")

Python 3.7.3 (/usr/bin/python3)
>>> %Run pyrebase.py
Traceback (most recent call last):
  File "/home/pi/pyrebase.py", line 1, in <module>
    import pyrebase
  File "/home/pi/pyrebase.py", line 10, in <module>
    firebase = pyrebase.initialize_app(config)
AttributeError: module 'pyrebase' has no attribute 'initialize_app'
>>>
