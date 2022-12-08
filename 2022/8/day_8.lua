function checkVisibility(forest,x,y)
	target = forest[y][x]
	visible = 4
	for i = 1, x-1 do
		if forest[y][i] >= target then 
		visible = visible -1 
		break
		end
	end
	for i = #(forest[y]), x+1,-1 do
		if forest[y][i] >= target then 
		visible = visible -1
		break 
		end
	end
	for i = 1, y-1 do
		if forest[i][x] >= target then 
		visible = visible -1 
		break
		end
	end
	for i = #(forest), y+1,-1 do
		if forest[i][x] >= target then 
		visible = visible -1
		break 
		end
	end
	if(visible > 0) then return 1 end
	return visible
end

function Vis(forest,x1,y1,x2,y2)
	current = forest[y1][x1]
	visible = 0
	step = ( x2 < x1 and -1 or 1)
	for i = x1 + step, x2, step do
		visible = visible + 1 
		if forest[y1][i] >= current then break end
	end
	if (x1 == x2) then visible  = 0 end
	if (visible ~= 0 )then return visible end;
	step = ( y2 < y1 and -1 or 1)
	for i = y1 + step, y2, step do
		visible = visible + 1 
		if forest[i][x1] >= current then break end
	end
	if (y1 == y2) then return 0 end
	return visible
end

forest = {}
lineNumber  = 1

while true do
	line = io.read()
	if (line == nil) then break end
	forest[lineNumber] = {}
	for i = 1, string.len(line) do forest[lineNumber][i] = tonumber(string.sub(line,i,i)) end
	lineNumber = lineNumber +1
end

sum = 0
maxScenicScore = 0

for i = 1, #(forest) do
	for j = 1, #(forest[i]) do
		sum = sum + checkVisibility(forest,j,i)
		scenicScore = Vis(forest,j,i,1,i)*Vis(forest,j,i,#(forest[i]),i)*Vis(forest,j,i,j,1)*Vis(forest,j,i,j,#(forest))
		if(scenicScore > maxScenicScore) then maxScenicScore = scenicScore end
	end	
end

io.write("Part 1 : " ,sum,"\n")
io.write("Part 2 : " ,maxScenicScore,"\n")