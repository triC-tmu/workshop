# 2022/04/30 勉強会
- 時間 : 14:00-17:00
- 場所 : 南大沢キャンパス図書館

## 内容
### 累積和
- 添え字でバグらせがち
    - 小さいケースを手計算するなどして丁寧に考察を...
- 素数判定
    - x が素数かどうか判定したい場合, 2 から x-1 まで調べると計算量的に間に合わない (O(N))
    - x が √x 以上の数で割り切れる場合, 必ず √x 以下の数でも割り切れるので, 2 から √x まで試せばよい
    - 計算量は O(√x)
- C++ は [std::exclusive_scan](https://cpprefjp.github.io/reference/numeric/exclusive_scan.html) を使うと楽
- 例題
    - [ABC037 C - 総和](https://atcoder.jp/contests/abc037/tasks/abc037_c)

### 二分探索