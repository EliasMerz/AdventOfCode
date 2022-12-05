<?php
	$input = fopen("input.txt", "r");
	$startingPositions = array();
	$stacksAmount = 0;
	while($stacksAmount == 0) {
		$line = fgets($input);
		if(str_starts_with(trim($line),'1')) $stacksAmount = substr(trim($line),-1);
		else array_push($startingPositions,$line);
		}
	$stacks = array();
	for($i = 0; $i < $stacksAmount; $i++){
		$stacks[$i] = array();
	}
	$index = count($startingPositions);
	while($index) {
		$crates = str_split($startingPositions[$index-1],floor(strlen($startingPositions[$index-1])/$stacksAmount));
		for($i = 0; $i < $stacksAmount; $i++){
			if(trim($crates[$i])) array_push($stacks[$i],substr(trim($crates[$i]),1,1));
		}
		$index--;
	}
	$stacks9001 = $stacks;
	while(!feof($input)){
		
		 list($amount ,$from, $to) =  sscanf(fgets($input),"move %d from %d to %d");
		 if(!$to) continue;
		 $last = array_key_last($stacks9001[$to-1]);
		 for($i = 0; $i < $amount; $i++){
			 array_push($stacks[$to-1],array_pop($stacks[$from-1]));
			 $stacks9001[$to-1][$last+$amount - $i] = array_pop($stacks9001[$from-1]);
		 }
		 ksort($stacks9001[$to-1]);
	}
	
	foreach($stacks as $key => $stack){
		echo end($stack);
	}
	echo "<br>";
	foreach($stacks9001 as $key => $stack){
		echo end($stack);
	}

fclose($input);
?>
