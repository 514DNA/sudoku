<h1 align = "center">ReadMe</h1>
<hr>
<h2>sudoku.exe</h2>
<ol>
	<li>通过命令行运行（参数顺序可改变，参数后必须有相应的数字）</li>
		<table align = "center" border = "1" style = "width: 100%">
			<colgroup>
				<col style = "width: 40%">
				<col style = "width: 60%">
			<colgroup>
			<thead>
				<tr><th>可用参数</th><th>参数说明</th></tr>
			</thead>
			<tbody>
				<tr><td>sudoku.exe -c [number]</td><td>1 <= number <= 1000000 且 number为整数</td></tr>
				<tr><td>sudoku.exe -s [absolute_path]</td><td>参数为文件所在的绝对路径，文件为txt格式，需保证文件内数独合法</td></tr>
				<tr><td>sudoku.exe -n [number] -m [mode]</td><td>1 <= number <= 10000 且 mode = (1|2|3)</td></tr>
				<tr><td>sudoku.exe -n [number] -r lower~upper</td><td>1 <= number <= 10000 且 20 <= lower <= upper <= 55 且lower~upper之间没有空格</td></tr>
				<tr><td>sudoku.exe -n [number] -r lower~upper -u</td><td>同上</td></tr>
				<tr><td>sudoku.exe -n [number] -u</td><td>1 <= number <= 10000</td></tr>
			</tbody>
		</table>
	<li>难度级别-m说明：
		<ul>
			<li>1：生成35个空的单解数独；</li>
			<li>2：生成40-50个空的单解数独</li>
			<li>3：生成50-60个空的单解数独</li>
		</ul>理由：在国际数独比赛中要求数独题目均为单解的标准数独，在个人体验中，也能感觉到多解数独会造成很大的困扰，因此统一生成单解数独。数独的难度很大程度上依赖空的个数有关，因此把空的个数作为数独难度的判别标准。
	</li>
</ol>
<h2>sudokuGUI.exe</h2>
<ul>
	<li>选择难度级别开始游戏</li>
	<li>点击空格输入数字1~9</li>
	<li>点击空格后，点击提示按钮，获得应填数字</li>
	<li>点击返回按钮，重新选择难度级别</li>
	<li>点击提交按钮，验证答案</li>
	<li>点击退出按钮，退出程序</li>
</ul>