
int main(int argc, char *argv[]) {
  if (argc <= 2)
  {
    cout << "Error! This program needs 2 param." << endl;
    return 0;
  }

  //take the strings as input
  char *s1 = argv[1];
  char *s2 = argv[2];

  //stores the lenght of strings s1 and s2
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  int dist[50][50];
  for(int i=0; i<=l1; i++) {
    dist[0][i] = i;
  }
  for(int j=0; j<=l2; j++) {
    dist[j][0] = j;
  }

  int t,track;
  int above_x, left_x, above_lef_x;
  for (int j=1; j<=l1; j++) {
    for(int i=1; i<=l2; i++) {
      if(s1[i-1] == s2[j-1]) {
        track= 0;
      } else {
        track = 1;
      }
      // calculate & store scores
      above_x = dist[i-1][j]+1;
      left_x = dist[i][j-1]+1;
      above_lef_x = dist[i-1][j-1]+track;
      t = min(above_x, left_x);
      dist[i][j] = min(t, above_lef_x);
    }
  }
  cout << "The Levinstein distance is:" << dist[l2][l1] << endl;
  return 0;
}