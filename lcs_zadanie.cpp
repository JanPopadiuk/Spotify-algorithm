#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================================
// ZADANIE: Longest Common Subsequence (LCS)
//
// Najdłuższy wspólny podciąg (LCS) to najdłuższa sekwencja znaków, która
// pojawia się w tej samej kolejności (ale niekoniecznie ciągło) w obu
// podanych ciągach.
//
// Przykład:
//   X = "ABCBDAB"
//   Y = "BDCABA"
//   LCS = "BCBA" lub "BDAB" (długość = 4)
//
// Zadanie oceniane jest poziomami — zaimplementuj tyle poziomów, na ile
// ocenę chcesz uzyskać. Każdy wyższy poziom zawiera poprzednie.
// ============================================================================


// ============================================================================
// OCENA 2 — Algorytm rekurencyjny (wykładniczy)
// ============================================================================
//
// TODO 1: Zaimplementuj funkcję lcs_brute(X, Y, m, n)
//
// Opis działania (rekurencja na prefiksach długości m i n):
//   1. Przypadek bazowy: jeśli m == 0 lub n == 0, zwróć 0
//   2. Jeśli X[m-1] == Y[n-1], to ten znak należy do LCS:
//      zwróć 1 + lcs_brute(X, Y, m-1, n-1)
//   3. W przeciwnym razie weź maksimum z dwóch możliwości:
//      - pomiń ostatni znak X: lcs_brute(X, Y, m-1, n)
//      - pomiń ostatni znak Y: lcs_brute(X, Y, m, n-1)
//
// Złożoność: O(2^(m+n)) — bardzo wolna, ale prosta
// Uwaga: nie używaj dla ciągów dłuższych niż ~20 znaków!
//
int lcs_brute(const string& X, const string& Y, int m, int n) {
	// UZUPEŁNIJ KOD
    if(m == 0 || n == 0){
    	return 0;
    }
    if(X[m-1]==Y[n-1]){
    	return 1 + lcs_brute(X, Y, m-1, n-1);
    }
		return max(lcs_brute(X, Y, m-1, n),lcs_brute(X, Y, m, n-1));
    
    
}


// ============================================================================
// OCENA 3 — Rekurencja z memoizacją (top-down DP)
// ============================================================================
//
// TODO 2: Zaimplementuj funkcję lcs_memo(X, Y, m, n, memo)
//
// Problemem algorytmu z oceny 2 jest wielokrotne obliczanie tych samych
// podproblemów. Memoizacja zapamiętuje wyniki w tablicy 2D.
//
// Kroki:
//   1. Przypadki bazowe: m == 0 lub n == 0 → zwróć 0
//   2. Jeśli memo[m][n] != -1, zwróć zapamiętany wynik
//   3. Oblicz wynik tak samo jak w lcs_brute
//   4. Zapamiętaj wynik w memo[m][n] przed zwróceniem
//
// Złożoność: O(m*n) czasu i O(m*n) pamięci
//
// Wskazówka: tablicę memo zadeklaruj w funkcji pomocniczej i zainicjalizuj
//            wartościami -1 (np. vector<vector<int>> memo(m+1, vector<int>(n+1, -1)))
//
int lcs_memo_helper(const string& X, const string& Y, int m, int n,
                    vector<vector<int>>& memo) {
	// UZUPEŁNIJ KOD
    if(m == 0 || n == 0){
    	return 0;
    }
    if(memo[m-1][n-1] != -1)
		return  memo[n-1][m-1];
	if(X[m-1]==Y[n-1]){
    	memo[m-1][n-1]=1+lcs_memo_helper(X, Y, m-1, n-1, memo);
    	return memo[m-1][n-1];
}
	memo[m-1][n-1] = max(lcs_memo_helper(X, Y, m-1, n,memo),lcs_memo_helper(X, Y, m, n-1,memo));
	return memo[m-1][n-1];
}

int lcs_memo(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return lcs_memo_helper(X, Y, m, n, memo);
}


// ============================================================================
// OCENA 4 — Programowanie dynamiczne (bottom-up DP)
// ============================================================================
//
// TODO 3: Zaimplementuj funkcję lcs_dp(X, Y)
//
// Zamiast schodzić rekurencyjnie od góry, buduj tablicę dp od dołu.
// dp[i][j] = długość LCS dla X[0..i-1] i Y[0..j-1]
//
// Kroki:
//   1. Utwórz tablicę dp[m+1][n+1] wypełnioną zerami
//   2. Dla każdego i od 1 do m:
//        Dla każdego j od 1 do n:
//          a) Jeśli X[i-1] == Y[j-1]:
//               dp[i][j] = 1 + dp[i-1][j-1]
//          b) W przeciwnym razie:
//               dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//   3. Zwróć dp[m][n]
//
// Złożoność: O(m*n) czasu i O(m*n) pamięci
// Zaleta nad memoizacją: brak narzutu rekurencji (przepełnienia stosu)
//
int lcs_dp(const string& X, const string& Y) {
	// UZUPEŁNIJ KOD
	int m = X.length();
    int n = Y.length();

    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}


// ============================================================================
// OCENA 5 — Odtwarzanie ciągu LCS (backtracking po tablicy DP)
// ============================================================================
//
// TODO 4: Zaimplementuj funkcję lcs_reconstruct(X, Y)
//
// Na podstawie tablicy dp z poprzedniego zadania odtwórz sam ciąg (nie tylko
// jego długość), cofając się od dp[m][n] do dp[0][0].
//
// Kroki odtwarzania (startuj od i=m, j=n):
//   Dopóki i > 0 i j > 0:
//     a) Jeśli X[i-1] == Y[j-1]:
//          dodaj X[i-1] na POCZĄTEK wyniku, i--, j--
//     b) Jeśli dp[i-1][j] >= dp[i][j-1]:
//          i--   (cofamy się w X)
//     c) W przeciwnym razie:
//          j--   (cofamy się w Y)
//
// Wskazówka: dodawanie na początek stringa jest kosztowne — możesz zbierać
//            znaki od tyłu i odwrócić string na końcu (reverse())
//
// Zwracaj: string będący jedną z możliwych sekwencji LCS
//
string lcs_reconstruct(const string& X, const string& Y) {
    // UZUPEŁNIJ KOD
}


// ============================================================================
// OCENA 6 — Optymalizacja pamięci (O(n) zamiast O(m*n))
// ============================================================================
//
// TODO 5: Zaimplementuj funkcję lcs_optimized(X, Y)
//
// Zauważ, że przy obliczaniu dp[i][j] potrzebujemy tylko poprzedniego wiersza
// dp[i-1][*]. Nie musimy przechowywać całej tablicy!
//
// Kroki:
//   1. Zamiast tablicy 2D użyj dwóch wektorów 1D: prev i curr (rozmiar n+1)
//   2. Dla każdego wiersza i:
//        Dla każdego j: wypełnij curr[j] tak jak dp[i][j]
//        Po przetworzeniu wiersza: prev = curr, wyzeruj curr
//   3. Zwróć prev[n]
//
// Złożoność: O(m*n) czasu, O(n) pamięci
// Uwaga: ta wersja NIE umożliwia odtworzenia ciągu (tylko długość)
//
// Dodatkowe wyzwanie (nieobowiązkowe): czy można zredukować do jednego wektora?
//   Wskazówka: zapamiętaj dp[i-1][j-1] w zmiennej tymczasowej przed nadpisaniem
//
int lcs_optimized(const string& X, const string& Y) {
    // UZUPEŁNIJ KOD
}


// ============================================================================
// Testy — NIE modyfikuj tej sekcji
// ============================================================================

void test_header(const string& title) {
    cout << "\n=== " << title << " ===\n";
}

int main() {

    // ------------------------------------------------------------------------
    // TESTY OCENA 2: lcs_brute
    // ------------------------------------------------------------------------
    test_header("OCENA 2: Algorytm wykładniczy (brute force)");

    string X1 = "ABCB", Y1 = "BCAB";
    cout << "X = \"" << X1 << "\", Y = \"" << Y1 << "\"\n";
    cout << "LCS dlugosc: " << lcs_brute(X1, Y1, X1.size(), Y1.size()) << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 3
    */

    string X2 = "AGGTAB", Y2 = "GXTXAYB";
    cout << "X = \"" << X2 << "\", Y = \"" << Y2 << "\"\n";
    cout << "LCS dlugosc: " << lcs_brute(X2, Y2, X2.size(), Y2.size()) << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    string X3 = "ABC", Y3 = "AC";
    cout << "X = \"" << X3 << "\", Y = \"" << Y3 << "\"\n";
    cout << "LCS dlugosc: " << lcs_brute(X3, Y3, X3.size(), Y3.size()) << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 2
    */

    // ------------------------------------------------------------------------
    // TESTY OCENA 3: lcs_memo
    // ------------------------------------------------------------------------
    test_header("OCENA 3: Rekurencja z memoizacja (top-down DP)");

    cout << "X = \"ABCBDAB\", Y = \"BDCABA\"\n";
    cout << "LCS dlugosc: " << lcs_memo("ABCBDAB", "BDCABA") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    cout << "X = \"AGGTAB\", Y = \"GXTXAYB\"\n";
    cout << "LCS dlugosc: " << lcs_memo("AGGTAB", "GXTXAYB") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    cout << "X = \"\" (pusty), Y = \"ABC\"\n";
    cout << "LCS dlugosc: " << lcs_memo("", "ABC") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 0
    */

    // ------------------------------------------------------------------------
    // TESTY OCENA 4: lcs_dp
    // ------------------------------------------------------------------------
    test_header("OCENA 4: Programowanie dynamiczne (bottom-up DP)");

    cout << "X = \"ABCBDAB\", Y = \"BDCABA\"\n";
    cout << "LCS dlugosc: " << lcs_dp("ABCBDAB", "BDCABA") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    cout << "X = \"AAAA\", Y = \"AAAA\"\n";
    cout << "LCS dlugosc: " << lcs_dp("AAAA", "AAAA") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    cout << "X = \"ABC\", Y = \"XYZ\"\n";
    cout << "LCS dlugosc: " << lcs_dp("ABC", "XYZ") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 0
    */

    // ------------------------------------------------------------------------
    // TESTY OCENA 5: lcs_reconstruct
    // ------------------------------------------------------------------------
    test_header("OCENA 5: Odtwarzanie ciagu LCS");

    string rx = "ABCBDAB", ry = "BDCABA";
    string result = lcs_reconstruct(rx, ry);
    cout << "X = \"" << rx << "\", Y = \"" << ry << "\"\n";
    cout << "LCS dlugosc: " << result.length() << "\n";
    cout << "LCS ciag:    \"" << result << "\"\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    LCS ciag:    "BCBA" lub "BDAB" lub "BCAB" (każda poprawna sekwencja długości 4)
    */

    string rx2 = "AGGTAB", ry2 = "GXTXAYB";
    result = lcs_reconstruct(rx2, ry2);
    cout << "X = \"" << rx2 << "\", Y = \"" << ry2 << "\"\n";
    cout << "LCS dlugosc: " << result.length() << "\n";
    cout << "LCS ciag:    \"" << result << "\"\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    LCS ciag:    "GTAB"
    */

    string rx3 = "ABCDE", ry3 = "ACE";
    result = lcs_reconstruct(rx3, ry3);
    cout << "X = \"" << rx3 << "\", Y = \"" << ry3 << "\"\n";
    cout << "LCS dlugosc: " << result.length() << "\n";
    cout << "LCS ciag:    \"" << result << "\"\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 3
    LCS ciag:    "ACE"
    */

    // ------------------------------------------------------------------------
    // TESTY OCENA 6: lcs_optimized (oszczędność pamięci)
    // ------------------------------------------------------------------------
    test_header("OCENA 6: Optymalizacja pamieci O(n)");

    cout << "X = \"ABCBDAB\", Y = \"BDCABA\"\n";
    cout << "LCS dlugosc: " << lcs_optimized("ABCBDAB", "BDCABA") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    cout << "X = \"AAAA\", Y = \"AAAA\"\n";
    cout << "LCS dlugosc: " << lcs_optimized("AAAA", "AAAA") << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 4
    */

    // Test na duzych danych (sprawdz ze O(m*n) czasu, ale O(n) pamieci)
    string big_x(500, 'A'), big_y(500, 'A');
    cout << "X = 500x'A', Y = 500x'A'\n";
    cout << "LCS dlugosc: " << lcs_optimized(big_x, big_y) << "\n";
    /*
    Oczekiwany wynik:
    LCS dlugosc: 500
    */

    return 0;
}
