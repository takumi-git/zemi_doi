/********************************************************************************
 * number.c -- ファイルの数字を調べ、小さい数から順に出力する。
 * ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PATH "/Volumes/SP PHD U3/GitHub/メディアシステム演習_土井担当回/pracitcefile/number.txt" // ～の部分は各自設定

struct node {
    int     value;            // このノードが保持している値
    struct  node *left_ptr;   // 左枝
    struct  node *right_ptr;  // 右枝
};
// ツリーの頂点 root
static struct node *root = NULL;

/********************************************************************************
 * make_tree   -- ノードを作成し、ツリーに数値を挿入
 *
 * パラメータ
 *      node   -- 現在のノード。ダブルポインタ（ポインタ変数へのポインタ）
 *      value  -- テキストから取り出した、挿入する数値
 ********************************************************************************/
void make_tree(struct node **node, int value)
{
    int  result;    // 数値の大小比較結果

    // ノードが存在しない場合
    if ((*node) == NULL) {

        // 新しい領域を割り当てノードを作成する
        (*node) = malloc(sizeof(struct node));
        if ((*node) == NULL){
            fprintf(stderr, "NULL");
            exit (8);
        }

        // メンバを初期化
        (*node)->left_ptr  = NULL;
        (*node)->right_ptr = NULL;
        (*node)->value     = value;

        // make_tree関数を終了
        return;
    }

    // テキストから取り出した数値をノードの数値と比較
    // 現在のノードより大きかったら正。小さかったら負。等しかったら0
    if ((*node)->value < value) {
        result = 1;
    } else if ((*node)->value > value) {
        result = -1;
    } else if ((*node)->value == value) {
        result = 0;
    }

    // 現在の数値が既にあれば、新たなノードは作成せずmake_tree関数を終了
    if (result == 0)
        return;

    // 大きかったら右枝に移動
    if (0 < result) {
        make_tree(&(*node)->right_ptr, value);
    }
    // 小さかったら左枝に移動
    else {
        make_tree(&(*node)->left_ptr, value);
    }
}

/********************************************************************************
 * check -- ファイル内の文字をチェックする。全て調べたら関数を終了。
 ********************************************************************************/
void check()
{
    char number[100];   // テキスト内のまとまった数字(10など）を１つ格納
    int  index;         // number配列のインデックス
    int  ch;            // 現在の文字 (characterの意)
    int  value;         // number配列の数字を整数に変換し格納
    FILE *text_file;    // 対象ファイル

    text_file = fopen(PATH, "r");
    if (text_file == NULL) {
        fprintf(stderr, "Error: Uable to open %s\n", PATH);
        exit (8);
    }

    // テキスト内の文字をすべて調べる
    while (1) {

        // 最初の数字をみつける
        // スペースや改行は飛ばす
        while (1) {
            // ファイルから１文字読み取る
            ch = fgetc(text_file);

            // 数字、または終端文字に行き着いたらループを抜ける
            if (isdigit(ch) || (ch == EOF))
                break;
        }

        // 終端文字の場合、ループを抜け関数を終了
        if (ch == EOF)
            break;

        // 文字配列の最初の要素に、取得した数字を挿入
        number[0] = ch;

        // 数字以外の文字や、改行・スペース、終端文字に行き着くまでループを繰り返し
        // 取得した文字を number 配列に挿入
        for (index = 1; index < sizeof(number); ++index) {
            ch = fgetc(text_file);
            if (!isdigit(ch))
                break;

            number[index] = ch;
        }

        // 文字列であることを示すため、終わりに終端文字を挿入
        number[index] = '\0';

        sscanf(number, "%d", &value);

        // 取得した数値を make_tree 関数に渡す
        make_tree(&root, value);
    }
    fclose(text_file);
}

/********************************************************************************
 * print_value -- 再帰関数。ツリー中の数値を小さい順から画面に出力
 *
 * パラメータ
 *      now    -- 出力するツリーのルート
 ********************************************************************************/
void print_value(struct node *now)
{
    if (now == NULL)
        return;

    print_value(now->left_ptr);
    printf("%d\n", now->value);
    print_value(now->right_ptr);
}

int main()
{
    check();
    print_value(root);

    return (0);
}