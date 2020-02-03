= 前書き

はじめまして！あっ！！あなた、もしかしてぱんつに興味がおあり
なお客様ですか？

えっ、きみのぱんつ見えてるよ...って...？きゃっ///！ も、もしかして、
私のぱんつ、み、みちゃったんですかぁ///？？ み、みないでくだしゃ
いよぉ///！！！

あれ、きょうはぱんつのおはなしじゃなくって...しーしゃーぷ...？
あっ、しーしゃーぷのおべんきょうに、わたしのとこまできてくれ
たんですね！

えっと、しーしゃーぷっていうのはですねっ！

2000年頃に登場したプログラミング言語。Microsoftのアンダース・
ヘルスバーグによって開発された。MicrosoftはC#を、マルチパラダ
イムプログラミング言語、強い型付け、命令型、宣言型、手続き型、
関数型、ジェネリック、オブジェクト指向の要素を持ったプログラミ
ング言語としており........

って、ああっ、待って！！ 帰らないでくだしゃいよぉ...！！

//blankline

本書はキッシュちゃんパンツパッチUnityEditorの機能の一部を作りながら、
@<kw>{UnityのC#スクリプトとエディタ拡張を学ぶ入門書}になります。

事前知識として、VRChatでアバターの改変を少しでもしたことがあるレベル
（つまり、基本的なUnityの操作が分かる程度）の Unityの知識を必要と
します。それ以外は日本語が理解できれば大丈夫な程度です。

ぜひ、本書を通じてUnityでのプログラミング、エディタ拡張の魅了を
少しでも感じてもらえれば幸いです。


== 免責事項

本書に記載された内容は、情報の提供のみを目的としています。したがって、
本書を用いた開発、製作、運用は、必ずご自身の責任と判断によって行ってください。
これらの情報による開発、製作、運用の結果について、著者はいかなる責任も負いません。

== 事前準備

=== 準備するもの
 * Unity
 * テキストエディタ
 * キッシュちゃんパンツパッチUnityEditor
 * CC0ぱんつモデル

Unityは著者の環境では Unity 2017.4.28f1を使用しています。本書では
著者と同じ環境のUnityがインストールされていることを前提として進めていきます。

テキストエディタは好きなものを使ってもらって大丈夫ですが、流石にメモ帳などでは書くのが辛いと思います。
著者のお勧めとしては Visual Studio Code が使いやすいのでお勧めです。

@<href>{https://azure.microsoft.com/ja-jp/products/visual-studio-code/}

キッシュちゃんパンツパッチUnityEditorはこちらからunitypackageを
ダウンロードできます。

@<href>{https://sansuke05.booth.pm/items/1582611}
//label[pantie-patche-editor]

CC0ぱんつモデルはてんてーさんによってこちらで配布されています。

@<href>{https://github.com/TenteEEEE/quiche_pantie_patch/wiki/CC0%E3%81%B1%E3%82%93%E3%81%A4}

=== Unityへのエディタの設定

メニューの「Edit」にある「Preference」を選択します。（Macの場合は「Unity」-> 「Preference」です。）

「External Tools」タブを選択し、エディタを選択します。（デフォルトでは Visual Studio か MonoDevelop が選べるようになってたかも...？）

使いたいエディタがタブにない場合は「Browse」ボタンから使いたいエディタの実行ファイル（.exeファイルなど）がある場所を探して実行ファイルを指定します。

Visual Studio Code をエディタとして指定した場合、次のような状態になっていればOKです。

//image[Editor][VSCodeを選んた場合のウインドウ]{
//}

最後に、メニューの「Assets」から「Open C# Project」を選択して、エディタが開くのを確認しましょう。

//image[OpenCSharpMenu][Open C# Projectを選択]{
//}

=== ぱんつ変換元画像のダウンロード

ぱんつの変換の元となる画像をダウンロードしてきます。

まずは、本書用の適当なUnityのプロジェクトを作成し、キッシュちゃんパンツパッチ
UnityEditorのunitypackageをインポートしてください。

そしてメニューの Editor -> PantiePatch -> データダウンロード を選択してください。

//image[PantiePatcheEditorMenu][メニューのデータダウンロードを選択]{
//}

次のようなウインドウが出るので、変換元テクスチャダウンロードの項目の
「ダウンロード」ボタンを押します。

//image[DownloadWindow][ダウンロードボタン]{
//}

すると、画像のダウンロードが開始されます。ダウンロードが完了すると、Assetsフォルダ内に次のように
AliceLaboratoryフォルダ、Dreamsフォルダが作成され、Dreamsフォルダの中に、名前に番号のふられた
画像が作成されていれば準備完了です！

//image[DownloadedFiles][ダウンロード後のProjectウインドウ]{
//}
