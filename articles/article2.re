
= Unityでネットワーク通信（ぱんつビュワーを作ってみよう！）

ふとこんなことを思ったことはありませんか？

「自分のアバターにぱんつを変換する前にぱんつの柄を3Dモデルで確認したい！」

ない...？そ、そんなこといわないでくださいよぉ〜 (> <)

ということで、この章では、CC0ぱんつモデルを使用して、好きなぱんつの柄を
CC0パンツモデルでプレビューできるパンツビュワーの作成を行います。

パンツビュワーの作成を通じて、制御構文、コルーチン、Unityでのネットワーク通信
などについて学んでいきましょう。

== 完成形のイメージ

もの作りはなんでもだと思いますが、まずは何を作るにしても完成形のイメージができている必要があります。

今回作るパンツビュワーはどんなものにしたいか具体的に書くと次のような感じです。

 * @<kw>{ぱんつの番号を入力すると、その番号のぱんつがCC0ぱんつに反映される}

これを実現するための方法を考えてみましょう。

ありがたいことに、キッシュちゃんパンツパッチには Web API が提供されており、
パンツパッチの変換をしてくれるサーバーにどのアバターのぱんつかという情報と
ぱんつの番号を送信すると、そのアバター用に変換されたぱんつの画像をダウンロード
できるようになっています。

今回はこの Web API を使ってみることにします。

ぱんつビュワーの処理の流れは次の図のように作っていくことにしましょう。

//image[ProcessFlow][パンツビュワーの処理の流れ]{
//}

ただし、今回は簡略化のため、ぱんつの番号はInspectorで指定するようにして
再生ボタンを押すと処理がはしるようにします。

== 関数を作る

それでは、制作に取りかかりましょう。

...と言いたいところですが、作り始める前にちょっと1章のおさらいと、関数についてもうすこし詳しく見てみます。

今までスクリプトは Start() というところにつらつらと書いてきました。

今までのスクリプトは数行のスクリプトですんでいますが、これが50行、100行も同じところに書いていったらどうなるでしょう。

そう、どこで何をしているのか分かんなくなります。

そうなることを避けるために、１章でも紹介した関数を作って処理を種類ごとに分けることにしましょう。

関数の書き方は、たとえば Debug.Log() で文字を出力する関数を書きたければ、次のように書きます。

//list[func1][Debug.Log()で文字を出力する関数][c#]{
public class NewBehaviourScript : MonoBehaviour 
{
        // 「ぱんつはいいぞ」を出力する関数
	void PrintString()
        {
            Debug.Log("ぱんつはいいぞ");
        }
    
	void Start ()
    　　{
	    PrintString();
	}
}
//}

PrintString()という関数を作ってStart()からPrintString()関数を呼び出しています。

よく見てみると、Start()と形がよく似ていますね。

そう、今まで処理を書いてきたStart()も実は関数です。

このStart()関数は名前のとおり、Sceneが始まる際にUnityから内部的に呼ばれる関数になります。

//list[funcDefinition][書き方の定義][c#]{
戻り値 関数名(引数の型 引数){
    処理
}
//}

