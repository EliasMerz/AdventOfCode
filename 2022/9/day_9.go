package main

import (
    "fmt"
)

type point struct {
    x  int
    y  int
}

func main() {
	var direction string
	var steps int
	var rope [10]point
	for i := range rope {
		rope[i] = point{1,1}
	}
	var part1 map[point]int = make(map[point]int)
	var part2 map[point]int = make(map[point]int)
	for {
		n, err := fmt.Scanf("%s %d\n", &direction,&steps)
		if n == 0 || err != nil {
			break 
		}
		for i := 0; i < steps; i++ {
			switch direction{
			case "R":
				rope[0].x++
			case "L":
				rope[0].x--
			case "D":
				rope[0].y--
			case "U":
				rope[0].y++
			}
			for i := 0; i < len(rope)-1;i++{
				move(&rope[i], &rope[i+1])
			}
			part1[rope[1]] = 1
			part2[rope[9]] = 1
		}
		
	}
	fmt.Printf("Part 1 : %d\n",len(part1))
	fmt.Printf("Part 2 : %d\n",len(part2))
}
func move(h *point , t *point){
	var xOffset  = h.x - t.x
	var yOffset  = h.y - t.y
	if abs(xOffset) > 1 || abs(yOffset) > 1 {
		t.x = t.x + sign(xOffset)
		t.y = t.y + sign(yOffset )
	}
}
func abs(x int) int{
	if x < 0 {
		return x * -1
	}
	return x
}
func sign(x int) int {
	if x < 0{
		return -1
	} else if x > 0{
		return 1
	}
	return 0
}