containedCounter = 0
overlapCounter = 0
while line = gets
	a = line.split(',',-1)[0].split('-',-1)[0].to_i
	b = line.split(',',-1)[0].split('-',-1)[1].to_i
	c = line.split(',',-1)[1].split('-',-1)[0].to_i
	d = line.split(',',-1)[1].split('-',-1)[1].to_i
	if( ( a <= c and b >= d ) or (a  >= c  and b  <= d ))
		containedCounter += 1
	end
	if((c <= a and a <= d) or (c <= b and b <= d) or (a <= c and c <= b) or (a <= d and d <= b))
		overlapCounter += 1
	end
end
puts containedCounter
puts overlapCounter