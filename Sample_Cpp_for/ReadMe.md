# Sample_Cpp_for
<https://youtu.be/Ts6q5dBh2BI>
## C++固有の range-based for
```c
for (宣言 : 配列やリストなど)
	文
```
要素を一つずつ取り出して文で処理する。
### 配列
```c
for (char ch : "ABC\0DEF") {
}
```
文字配列中の１文字が chに設定される。
Null文字('\0')でも特別扱いはない。
上の例では文字配列中に二つの Null文字がある。（末尾にも'\0'が隠れている）

### 参照

要素のコピーを避けるには参照を宣言する。

