function Node(name,val,prev) {
	this.name = name;
    this.val = val;
    this.children = [];
	this.prev = prev;
  };
const fs = require("fs");

var root;
var name;
var current;

const input = fs.readFileSync("input.txt","utf-8" );
input.split(/\r?\n/).forEach(line => {
	if(/^\$ cd .*$/.test(line)){
		name = line.replace("$ cd ","")
		if(!root){
			root = new Node(name,0,null);
			current = root;
			return;
		}
		if(name == ".."){
			current = current.prev;
		}
		else{
			current.children.push(new Node(name,0,current));
			current = current.children[current.children.length - 1 ];
		}
	}
	else if(/^^\d* .*$/.test(line)){
		var vals = line.split(" ");
		current.children.push(new Node(vals[1],vals[0],current));
	}
});
var min = dirSize(root);
var target =  30000000 - (70000000 - min);
console.log(totalSum(root));
console.log(findSmallestDir(root,target,min));

function dirSize(root){
	var sum = 0;
	if(root.children.length == 0) sum =  Number(root.val)
	root.children.forEach(child => {
		sum += dirSize(child);
	});
	return sum ;
}
function totalSum(root){
	var sum = 0;
	var size = 0;
	root.children.forEach(child => {
		if(child.children.length != 0) size = dirSize(child);
		if( size <= 100000){sum += size;}
		sum += totalSum(child);
	})
	return sum;
}
function findSmallestDir(root,target,min){
	var size = 0;
	root.children.forEach(child => {
		if(child.children.length != 0) size = dirSize(child);
		if(size< min && size >= target) min = size;
		min =  findSmallestDir(child,target,min);
	}); 
	return min;
}