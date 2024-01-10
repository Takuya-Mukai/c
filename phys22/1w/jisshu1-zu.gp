#!/usr/bin/gnuplot -persist
#
# set terminal x11 
# set output

#タイトル
set title ' Lissajous Figures'

# x座標の説明
set xlabel ' cos(a t)'

# y座標の説明
set ylabel ' sin(b t)'

# 凡例を図の外に
set key out       

# 図のサイズ、縦横比を1に
set size ratio 1  

# zu.data  ステップ 時間         cos(at)      sin(bt)
# zu.data    1      1.00000E-02  9.99550E-01  2.08701E-02


#  xの範囲、 yの範囲  ファイルの名前 データ順番  用いる数値 曲線を使う 線種(色) 線幅

#plot[-1.1:1.1][-1.1:1.1] 'jishu1-zu.data'  i 0:0:1     u 3:4  t 'a=1, b=1'    w l       lt 3    lw 1
plot[-1.1:1.1][-1.1:1.1] 'jisshu1-zu.data'  i 0:0:1     u 3:4  t 'a=1, b=1'    w l       lt 3    lw 1

pause -1     # リターンキーを押すまで図を消さない。

#plot[-1.1:1.1][-1.1:1.1]  'jishu1-zu.data' i 5:5:1      u 3:4  t 'a=5, b=6'     w l       lt 3    lw 1
plot[-1.1:1.1][-1.1:1.1]  'jisshu1-zu.data' i 5:5:1      u 3:4  t 'a=5, b=6'     w l       lt 3    lw 1

pause -1
#    EOF
