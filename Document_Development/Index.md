﻿## 開発者向け資料

### コンテンツ

[ロードマップ・現在のタスク](Task.md)

[コンパイル手順](HowToCompile/HowToCompile.md)

[コーディング規約](CodingRule.md)

[コメント規約](CommentRule.md)

[GPUに関する情報](GPU.md)

### 新規ライブラリ、リソース等の追加について

ライブラリに関しては、MIT License、zlib等のライセンスである場合、追加して問題ありません。

サンプルに外部のリソースを使用する場合、ライセンス表記をよく見て、その都度判断してください。

ランタイム(ユーザーがゲームに使用するDLL)にライブラリを追加する場合、``` LICENSE ``` と ``` LICENSE_TOOLS ``` にライセンスを追記します。

ツールにライブラリを追加する場合、 ``` LICENSE_TOOLS ``` にライセンスを追記します。

サンプルに外部のリソースを追加する場合、 ``` LICENSE_RESOURCES ``` にライセンスを追記します。

極力、ライブラリはバイナリファイルをgitの管理下に置かず、pythonでインストールできるようにします。

インストール用のスクリプトができたら、 ``` Script ``` ディレクトリに配置し、インストール方法に実行の手順を追記します。

### C#版を開発する際のコード自動生成について

ラッパー生成ツールを使用して、swigのラッパーの一部を生成することができます。
C++のEngine側(ace_engineプロジェクト)を編集した人は以下の手順を実行する必要があります。

#### 手順

1. C++ Engine側のヘッダ(ace.h)を生成します。Dev/generateEngineHeader.pyを実行してください。
2. Doxygenのxmlドキュメントを生成します。Script/export_cpp_xml.pyを実行してください。
3. swigによるC++/C#の接続コードを生成します。Dev/generate_swig.pyを実行してください。
4. ラッパーを生成します。Script/generateSwigWrapper.pyを実行してください。