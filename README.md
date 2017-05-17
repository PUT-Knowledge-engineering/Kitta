# WhichEye

Biblioteka napisana w C++ rozpoznająca czy zdjęcie dna oka przedstawia oko prawe czy lewe.

# macOS_Example

Aplikacja wsadowa napisana w C++. Przykład wykorzystania biblioteki `WhichEye` na platformę macOS.
W folderze apliakcji znajduje się skompilowana aplikacja `whichEye`.

## Użycie

```shell
$ ./whichEye --help

Usage: 
$ whichEye [--help][--verbose][--info] <image_file_path>

 -h  --help  		Prints this help 
 -i  --info         Prints brightest region info 
 -v  --verbose  	Prints more debuggig information 

```

Podstawowe użycie zwraca:
  - r - oko prawe
  - l - oko lewe
  - u - aplikacja nie była w stanie ustalić które oko

Np.
```shell
$ ./whichEye /Users/rafalkitta/Downloads/eye.png
r
```

Użycie z flagą `-i` zwraca bogatsze informacje o rozpoznanym typie oka.
Np.
```shell
$ ./whichEye -i /Users/rafalkitta/Downloads/eye.png 
======================
Image anylize summary:
  Eye type            : right
  Optic nerve location: [390, 311]
======================
```

Użycie z flagą `-v` zwraca rezultaty poszczególnych procesów aplikacji.
```shell
./whichEye -v /Users/rafalkitta/Downloads/lena.png 
Start analyzing image...
Read image from file path: OK
Converted image to gray scale: OK
Added Gaussian blur with radius 21: OK
Determined brightest region (and its location) of the image: OK
Determined which eye it is: OK
End analyzing image.
r
```

