'#id';
'.class';
'element';
'input[type="text"]';
'input#banan'; // input med id banan
'input #banan'; // Något med id banan inne i en input

document.querySelector('input[type="text"]').addEventListener('input', logger);
document.querySelector('input[type="password"]').addEventListener('input', logger);

function logger(e) {
	console.log(e.target);
	console.log(e.target.type);
	console.log(e.target.value);
}