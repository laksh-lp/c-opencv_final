import cv2

camera = cv2.VideoCapture(0)
i=0;
while(1):
	ret,frame = camera.read()
	cv2.imshow("display",frame)
	#size=[640,480]
	k = cv2.waitKey(25)
	if(k == 32):
		cv2.imwrite(str(i)+".jpg",frame)
		frame=cv2.resize(frame,(640,480))
		i=i+1
	elif(k == 27):
		break
cv2.destroyAllWindows()
camera.release()

	