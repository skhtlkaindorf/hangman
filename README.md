# hangman

hangman.c zeigt ein Beispiel, wie eine Textdatei mit Wörtern, Zeile für Zeile gelesen werden kann und der Inhalt auf der Konsole ausgegeben wird.
Auf Basis von diesem Beispiel soll eine einfache Version von Hangman implementiert werden. Der Spieler hat dabei maximal 6 Versuche, um das Wort zu erraten. 

Beispiel:
Es wird das Wort "hello" geladen und der Spieler soll dieses erraten. Folgende Aussgabe auf der Konsole:
```
Neues Spiel mit einem Wort mit 5 Buchstaben wurde geladen:
_ _ _ _ _
Welches Zeichen?: e
Gratulation:  _ e _ _ _
Welches Zeichen?: a
Oh-je:        _ e _ _ _
Hangman: 


/
Welches Zeichen: i
Oh-je:        _ e _ _ _
Hangman: 


/ \
Welches Zeichen: l
Gratulation:  _ e l l _
Hangman: 


/ \
Welches Zeichen: x
Oh-je:        _ e l l _
Hangman: 

 |
/ \
Welches Zeichen: k
Oh-je:        _ e l l _
Hangman: 
\
 |
/ \
Welches Zeichen: o
Gratulation:  _ e l l o
Hangman: 
\
 |
/ \
Welches Zeichen: m
Oh-je:        _ e l l o
Hangman: 
\ /
 |
/ \
Welches Zeichen: h
Gratulation:  h e l l o

Neues Spiel starten [j/n]?
```


### string.h
Von string.h werden zwei Funktionen benötigt.

**strlen**
```
char demoText[100] = "Hallo";
strlen(demoText); // liefert die Länge eines Strings => in dem Fall 5
```

**strcpy**
```
void copy(char *ch) {
   strcpy(ch, "text");
}

copy(demoText);
printf("%s", demoText); // prints text
```

### 1. Ein zufälliges Wort laden
Es ist eine Funktion `void loadWord(char *word)` zu schreiben, welche ein zufälliges Wort aus der Datei einliest und retour liefert.
Dafür ist ein Zufallswert zwischen 1 und 15 zu bilden und das jeweilige Wort soll mittels strcpy nach word kopiert werden. Die Funktion sollte in der main-Funktion getestet werden.

### 2. printHangman
Es ist eine Funktion `void printHangman(int wrongAttempts)` zu schreiben. Diese soll auf der Console ein abstraktes Bild einer Strichfigur zeichnen. wrongAttempts gibt dabei an, viele falsche Versuche es bereits gab.

Beim Wert 1 beginnt die Figur mit einem Fuß.
```

 
/ 
```

Beim Wert 6 ist die komplette Figur auszugeben.
```
\0/
 |
/ \
```

### 3. printHiddenWord
Es ist eine Funktion `void printHiddenWord(char word[])` zu schreiben. Diese übernimmt einen char-Array und gibt davon Zeichen für Zeichen, getrennt durch ein Leerzeichen, aus.
"text" => "t e x t"

### 4. uncoverCharacter
Die Funktion `int uncoverCharacter(char word[], char hiddenWord[], char inputCharacter)` überprüft, ob das eingelesene Zeichen (inputCharacter) im Wort (word) enthalten ist. Wenn ja, dann wird das Zeichen im verdeckten Wort (hiddenWord) aufgedeckt und 1 als Ergebnis retour geliefert. Wird das Zeichen nicht gefunden, dann wird 0 retour geliefert. 

### 5. allCharactersUncovered
Die Funktion `int allCharactersUncovered(char word[])` überprüft, ob im übergebenen char-Array ein '_' (Underscore) enthalten ist. Wenn ja, dann liefert sie 0 zuürck. Sind alle Zeichen aufgedecket und befindet sich im char-Array kein '_' (Underscore) mehr, dann liefert die Funktion 1 zurück.

### 6. main
In der main-Funktion ist die eigentlichen Programmlogik abzubilden. Mittels der Funktion `loadWord` ist ein Wort zu laden. Ein zweites char-Array (zB.: `char hiddenWord[100]`) ist mit '_' (entsprechend der Länge des geladenen Worts) zu befüllen. 
Buchstaben sind entsprechend der oben definierten Konversation einzulesen. Mittels `uncoverCharacter` kann ein Zeichen aufgedecket werden. Liefert die Funktion 0 retour, so handelt es sich um einen fehlerhaften Zug des Spielers, welcher mitgezählt werden muss und an `printHangman` übergeben werden muss.
`printHiddenWord` und `allCharactersUncovered` helfen bei der weiteren Spiellogik. Nachdem das Spiel beendet ist (erfolgreich oder nicht), soll der Spieler gefragt werden, ob ein neues Spiel gestartet werden soll.



