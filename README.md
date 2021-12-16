# dena-review

## 四目並べ
二人のプレイヤーが縦6横7のボードの上で交互にコマを下から積み重ねて、先に縦、横、斜めいずれかに直線状に4つ並べた方が勝つゲーム。
誰も並べられなかった場合、引き分けとなる。

![yonmoku](https://user-images.githubusercontent.com/60804160/146204073-8ba1ca22-2cf6-4ce5-9da6-8487761ad76e.gif)

## バージョン
```bash
$ clang -v
Homebrew clang version 13.0.0
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /usr/local/opt/llvm/bin

$ make -v
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
```


 ## 遊び方
 ```bash
$ git clone https://github.com/public-jun/dena-review.git
$ cd denea-review
$ make
$ ./Yonmoku
 ```
