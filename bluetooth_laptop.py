import serial
import time
import keyboard

print("Start")
port = "COM24"  # 控制面板--> 设备和打印机 --> HC-05属性
bluetooth = serial.Serial(port, 9600)  # Start communications with the bluetooth unit
print("Connected")
bluetooth.flushInput()  # This gives the bluetooth a little kick

while True:  # send 5 groups of data to the bluetooth
    # print("Ping")
    # bluetooth.write(str.encode(str('1')))  # These need to be bytes not unicode, plus a number

    # input_data = bluetooth.readline()          # This reads the incoming data. In this particular example it will be the "Hello from Blue" line
    # print(input_data.decode())                 # These are bytes coming in so a decode is needed
    # time.sleep(1)  # A pause between bursts

    if keyboard.is_pressed('w'):
        bluetooth.write(str.encode(str('1')))
        time.sleep(0.2)

    if keyboard.is_pressed('s'):
        bluetooth.write(str.encode(str('2')))
        time.sleep(0.2)

    if keyboard.is_pressed('d'):
        bluetooth.write(str.encode(str('3')))
        time.sleep(0.2)

    if keyboard.is_pressed('a'):
        bluetooth.write(str.encode(str('4')))
        time.sleep(0.2)

    if keyboard.is_pressed('e'):
        bluetooth.write(str.encode(str('5')))
        time.sleep(0.2)

    if keyboard.is_pressed('q'):
        bluetooth.write(str.encode(str('6')))
        time.sleep(0.2)

    if keyboard.is_pressed('p'):
        print("Disconnect bluetooth")
        break

    else:
        bluetooth.write(str.encode(str('0')))

bluetooth.close()