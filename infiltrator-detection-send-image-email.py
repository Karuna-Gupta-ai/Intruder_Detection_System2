import smtplib
import filetype
from email.message import EmailMessage
import cv2
import serial
import time

# Setup Serial
s = serial.Serial('COM2', 9600, timeout=1)
time.sleep(2)  # Let serial settle

# Setup Camera
camera = cv2.VideoCapture(0)
i = 0

while i < 2:
    print("Waiting for serial input...")
    serial_data = s.read().decode('utf-8').strip()
    
    if serial_data == 'a':
        print("Theft detected! Sending image via email.")
        ret, image = camera.read()
        if not ret:
            print("Failed to capture image.")
            continue

        cv2.imwrite('theif.png', image)
        i += 1

        Sender_Email = "kgupta7676@gmail.com"
        Receiver_Email = "karunagupta110105@gmail.com"
        Password = "corunfsjftvzvpru"
        newMessage = EmailMessage()
        newMessage['Subject'] = "Alert: Theft inside your home"
        newMessage['From'] = Sender_Email
        newMessage['To'] = Receiver_Email
        newMessage.set_content("Motion detected. See attached image.")

        with open('theif.png', 'rb') as f:
            image_data = f.read()
            file_type = filetype.guess(image_data)
            if file_type:
                image_type, image_subtype = file_type.mime.split('/')
                newMessage.add_attachment(image_data, maintype=image_type, subtype=image_subtype, filename='theif.png')

        try:
            with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
                smtp.login(Sender_Email, Password)
                smtp.send_message(newMessage)
            print("Email sent successfully.")
        except Exception as e:
            print(f"Failed to send email: {e}")

# Cleanup
camera.release()
s.close()
