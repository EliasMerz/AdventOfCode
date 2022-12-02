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
			score = score + (b - 88) * 3
			if (b == 89) then
				score = score + a - 64
			else if(b == 88) then
				if(a == 65) then
					score = score + 3			
				else
					score = score + a - 65
				end if
			else if(b == 90) then
				if(a == 67) then
					score = score + 1			
				else
					score = score + a - 63
				end if
			end if
		END IF
	END DO
	print * , score
end program hello