program hello
	INTEGER :: Reason
	CHARACTER :: a_in
	CHARACTER :: b_in
	INTEGER :: a
	INTEGER :: b
	INTEGER :: score
	score = 0
	DO
		READ(*,*,IOSTAT=Reason) a_in, b_in
		IF (Reason < 0) THEN
			print *, 'End of file'
			exit
		else if (Reason == 0) then
			a = iachar(a_in)
			b = iachar(b_in)
			score = score +  b - 87
			IF(a == b - 23) then
				score = score + 3
			else if (b == a + 24 ) then
				score = score + 6
			else if (b == a + 21 ) then
				score = score + 6
			end if
			
		END IF
	END DO
	print * , score
end program hello