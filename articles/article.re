
= はじめてのC#（ぱんつをUnityに表示してみよう！）

この章では、UnityのScene上にキッシュちゃん素体用のぱんつを表示するプログラムを書いてみます。

このプログラムを通して、変数や型、画像の読み込み、Unity のコンポネントの使い方などについて学んでいきましょう。

== Unityでスクリプトを準備する

それでは、VRChatのアバターやワールドを作る時のようにおもむろにUnity
を開きましょう。

Project ウインドウを右クリックして Create -> C# Script を選択します。

すると、Project ウインドウに NewBehaviourScript というファイルができあがります。

NewBehaviourScript をダブルクリックすると準備のときに設定したエディタが立ち上がります。

これで、Unityで C# を書く準備完了です！

== Hello World

=== 文字列の出力

プログラミングをするのははじめてですか？

ならプログラミングする皆が通る最初の儀式をやってみましょう。

プログラムで「文字列を出力する」という儀式です。

文字列とは「ABC」のような単語や文章のことを指します。
（1単語のものは文字と表現します。）

では早速やってみましょう。

先ほど作ったファイルはデフォルトの状態では次のようになっていると思います。

//list[default][scriptファイルの最初の状態][c#]{
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
//}

この void Start() {} となっている {} の中に次の文を追加してみましょう。

//list[hello][Hello World][c#]{

// ConsoleにHello Worldと表示する
Debug.Log("Hello World");

//}

Unityに戻って、Hierarchy ウインドウに適当なオブジェクト（CreateEmptyなど）を作成し、
Inspector ウインドウの Add Component から上の文を追記したScriptファイルを追加しましょう。

そして、上の方にある "▶︎" の再生ボタンを押します。

すると、Console ウインドウに下のような文が出てきたのではないでしょうか。（もし出てきてないよ！
って人は Console ウインドウの右の方にある ”！” のマークのボタンを押してみてください）

//image[HelloWorld][HelloWorld出力結果]{
//}

おめでとうございます！ようこそ C# の世界へ！これにて入門完了です！

今回使った、Debug.Log()は、Unityで Console へ文字列を出力するための
ものです。

C#では使いたい文字列を "" で囲うことで文字列として扱うことができます。

たとえば、"Hello World" を次のように変更してみましょう。

//list[eat_pantie][変更後][c#]{
Debug.Log("ぱんつ食べたい");
//}

//image[EatPantie][変更後の結果]{
//}

......大変な変態さんですね！！！

すみません。

話を戻すと、このように "" の中を書き換えることで別の文字列を表示することができます。

=== C#の行末

C#ではプログラムの命令文（Debug.Log()などのブログラムを記述する文）の行末には
セミコロン（;）をつける必要があります。

これは C# を書くときのお約束として決まっているものなので忘れないようにしましょう。

=== コメント

Debug.Log()の上にある//以降はコメントと呼ばれ、C# のプログラムとして
実行されません。

プログラムに書き残したいことがあればこのコメントを使うようにしましょう。

== 画像の読み込み

=== 変数と型

それでは、ぱんつを表示するプログラムの制作に入りましょう。

まずは表示させたい画像をプログラムに読み込む必要があります。

事前準備でダウンロードしてきた画像は次のようになっていましたね。

//image[DownloadedFiles][読みこみたいぱんつたち]{
//}

これらの、たとえば0001の画像の場所は文字列として次のように書くことができます。

//list[path][画像の場所（Path）][c#]{
"Assets/AliceLaboratory/Dreams/0001.png"
//}

このような、ファイルやフォルダの場所を文字列で表したものをパス（Path）と言います。

このように文字列を直接書くのもいいですが、複数のぱんつを読み込むなど、
何度も使うことになると面倒です。

そこで、@<kw>{変数}を使って使い回せるようにしましょう。

//list[string_value][変数][c#]{
string dreamDir = "Assets/AliceLaboratory/Dreams/"
//}

今回は dreamDir という名前の@<kw>{変数}を用意し、そこに"Assets/AliceLaboratory/Dreams/"
という文字列を@<kw>{代入}しました。

==== 変数

変数は何かを入れたり、出したりできる「箱」のようなものをイメージして
もらえればいいです。

ただし、この箱には指定した形式のものしか入れることができません。（一部例外はありますが...）

今回は文字列の形式を入れることができる変数を用意しました。

この、変数に入れることのできる形式のことを@<kw>{型（Type）}と言います。

C#で文字列型はstringという名前で表されます。

==== 代入

変数に文字列などのものを入れる処理のことを@<kw>{代入}といい、=を使って次のように書きます。

//list[assignment][代入の処理][c#]{
型の名前 変数名 = 代入するもの;
//}

算数では=はイコールですが、C#のプログラムでは代入の意味になり、比較にはまた別の書き方をします。
（そちらは別の節で紹介します。）

==== 型

すべての変数には@<kw>{型（Type）}が存在します。

先ほどのstring（文字列型）以外にも整数を表す型や少数を表す型など、さまざまな型があります。

代表的なものは次のようなものです。

