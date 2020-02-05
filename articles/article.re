
= はじめてのC#（ぱんつをUnityに表示してみよう！）

この章では、UnityのScene上にキッシュちゃん素体用のぱんつを表示するスクリプトを書いてみます。

このスクリプトを通して、変数や型、クラス、オブジェクト、Unity のコンポネントの使い方などについて学んでいきましょう。

== Unityでスクリプトを準備する

それでは、VRChatのアバターやワールドを作る時のようにおもむろにUnity
を開きましょう。

最初に、Unityのエディタ上にConsoleウインドウが出ていることを確認してください。スクリプトを書く上で、
Consoleウインドウはよく使うので常に出しておくといいでしょう。

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

public class NewBehaviourScript : MonoBehaviour 
{
	// Use this for initialization
	void Start ()
    　　{
		
	}
	
	// Update is called once per frame
	void Update ()
    　　{
		
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

それでは、ぱんつを表示するスクリプトの制作に入りましょう。

まずは表示させたい画像をスクリプトに読み込む必要があります。

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
（そちらは後ほど紹介します。）

==== 型

すべての変数には@<kw>{型（Type）}が存在します。

先ほどのstring（文字列型）以外にも整数を表す型や少数を表す型など、さまざまな型があります。

代表的な型は次のようなものがあります。

 * 整数型：int
 * 浮動小数点数型（少数を表す型）：float
 * ブール値（trueかfalseを表す）：bool
 * 文字列型：string

=== クラスと関数

それでは、dreamDir変数を使って画像を読み込んでいきます。

ファイルの読み書きをC#で行う際には、Fileという@<kw>{クラス}を使用します。

@<kw>{クラス}とは、簡単にいえば先ほどの変数と、@<kw>{関数}が一緒
になって入っているものです。

@<kw>{関数}とは、いろんな処理をまとめたものです。

イメージとしては次の図のような感じになります。

//image[Class][クラスと関数のイメージ図]{
//}

Fileクラスを使うには次のようにファイルの先頭にFileクラスの入った
クラスの集まりを読み込みますという宣言を記述してあげる必要があります。

//list[using_file_modules][モジュールの読み込み宣言][c#]{
using System.IO;
//}

そして、ファイルの読み込みは、@<kw>{File.ReadAllBytes(読み込みたい画像の場所)}
のように指定します。

ReadAllBytes()がFileクラスの持った関数で実際にファイルを読み込む処理を行います。

dreamDir変数を使って場所を指定すると、次のようになります。

//list[ReadImage][画像の読み込み][c#]{
File.ReadAllBytes(dreamDir + "0001.png");
//}

+で文字列を連結でき、連結した結果は"Assets/AliceLaboratory/Dreams/0001.png"になります。

=== クラスと型

さて、Fileで画像を読み込む処理はかけましたが、読み込んだ画像を画像の変数として
格納してあげる必要があります。

これには@<kw>{Texture2D}というクラスを使います。

Texture...そう！あのアバターを改変する時にお世話になっているTextureです。

@<kw>{Texture2D}クラスはUnityのC#でテクスチャを扱う時に使うクラスになります。

このクラスを使って読み込んだ画像をテクスチャとして変数に格納します。

まず、次のようにクラスの変数を用意します。

//list[instantiate][クラスの変数を用意する][c#]{
Texture2D tex = new Texture2D(0, 0);
//}

型をかく場所にTexture2Dが指定されていますね。

このように、クラスも型として指定することができます。

そして@<kw>{クラスを型として定義された変数}を、@<kw>{オブジェクト}と言います。

ここでは、@<kw>{new}というキーワードを使ってTexture2Dクラスを使ってtexというオブジェクト
を作るよ！という宣言をしています。

（）の中の２つの0は最初は空の何もないテクスチャを用意するよというのを表しています。

読み込んだ画像をテクスチャとして格納するにはTexture2Dの
@<kw>{LoadImage()}関数を使います。

すると、最終的に先ほどのFileクラスを使った画像の読み込みと合わせて次の
ようにかけます。

//list[load_image][最終的な画像の読み込み処理]{
Texture2D tex = new Texture2D(0, 0);
tex.LoadImage(File.ReadAllBytes(dreamDir + "0001.png"));
//}

ここまでで、全体のスクリプトとしては次のようになっていると思います。

//list[load_image_all][画像読み込みスクリプトの全体]{
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

public class NewBehaviourScript : MonoBehaviour 
{
	void Start () 
    　　{
        　　string dreamDir = "Assets/AliceLaboratory/Dreams/";

        　　Texture2D tex = new Texture2D(0, 0);
        　　tex.LoadImage(File.ReadAllBytes(dreamDir + "0001.png"));
	}
	
	void Update () 
    　　{
		
	}
}
//}

== 画像の表示

=== コンポネントを使う

さて、ここまで来たらいったんUnityの方へ戻りましょう。

Hierarchyを右クリックして、「3D Object」-> 「Quad」を選択してQuadを作成します。

QuodのInspectorへ今まで作ってきたスクリプトをドラッグ&ドロップしてAttachさせておきます。

//image[Inspector][このようにScriptが追加されていればOK]{
//}

そうしたら、スクリプトの方へ戻りましょう。

ここから最後の工程。読み込んだテクスチャをAttachしたQuadに貼り付けます。

テクスチャをスクリプトで貼り付けるためには、まずQuadのRendererというコンポネントを呼び出す必要があります。

今AttachされているQuad（GameObject）のコンポネントを呼び出すためには、@<kw>{GetComponent}というものを使って
次のように書きます。

//list[get_renderer][Rendererコンポネントの呼び出し][c#]{
Renderer r = GetComponent<Renderer>();
//}

ん、型の部分にはRendererが指定されていますね。

実はUnityのスクリプトではコンポネントもクラスとして扱われます。

よく見るTransformや、コライダーなんかも、実はクラスや
オブジェクトだったわけです！（な、なんだってー！）

そう考えると、Rendererからテクスチャを呼び出す次の処理も理解できると思います。

//list[get_texture][Rendererからテクスチャを呼び出す処理]{
r.material.mainTexture
//}

Texture2Dのところでも出てきましたが、@<kw>{オブジェクト.関数}や@<kw>{オブジェクト.変数}で、
オブジェクトに含まれる関数や変数を呼び出すことができます。

（Fileの場合は クラス.関数 でしたが、中にはこのようにクラスをオブジェクト化しなくても
呼び出せるものもあります）

今回はRendererのオブジェクトにすでに定義されている、Materialのオブジェクトを呼び出し、
さらにそのMaterialのオブジェクトに定義されているTextureのオブジェクト「mainTexture」
を呼び出しています。

そして、これに読み込んだテクスチャを代入します。

//list[set_texture][読み込んだテクスチャ画像を代入]{
r.material.mainTexture = tex;
//}

これでぱんつ表示スクリプトの完成です！

全体のスクリプトは次のような感じです。

//list[show_pantie_script_all][ぱんつ表示スクリプトの全体]{
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

public class NewBehaviourScript : MonoBehaviour 
{
	void Start () 
    　　{
        　　string dreamDir = "Assets/AliceLaboratory/Dreams/";

        　　Texture2D tex = new Texture2D(0, 0);
        　　tex.LoadImage(File.ReadAllBytes(dreamDir + "0001.png"));
        　　
        　　Renderer r = GetComponent<Renderer>();
        　　r.material.mainTexture = tex;
	}
	
	void Update () 
    　　{
		
	}
}
//}

さてそれではUnityに戻って再生ボタンを押してみましょう！

次のように、Quadに画像が表示されれば完成です！お疲れ様でした！

//image[Pantie][ぱんつ召喚！]{
//}
