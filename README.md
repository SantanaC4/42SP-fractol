# 42SP-fractol

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)

The term fractal was first used by mathematician Benoit Mandelbrot in 1974,
he based it on the Latin word fractus, meaning "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which has a similar
pattern whatever the scale.

## Mandelbrot set

<img src="https://github.com/SantanaC4/42SP-fractol/blob/main/mandelbrot.png"/>

## Julia set -8.35 -0.2321

<img src="https://github.com/SantanaC4/42SP-fractol/blob/main/julia_-8_35_-0.2321_3.png"/>

## Goals

This is the first project in which we use the graphical library [`miniLibX`](https://github.com/42Paris/minilibx-linux).
This project also gives the opportunity to make use of the mathematical notion of complex numbers and to take a peek at the concept of optimization in computer graphics.


## Mandatory

• The software should offer the Julia set and the Mandelbrot set.

• Mouse wheel zooms in and out.

• Use at least a few colors to show the depth of each fractal.

• A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits properly.


## References

### Fractol: Mandelbrot

https://www.youtube.com/watch?v=fAsaSkmbF5s&t=445s

### Fractol: Julia
https://www.youtube.com/watch?v=6z7GQewK-Ks&t=24s

### Colors

[https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf](url)
https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf

## Requirements

### Minilibx
Install its dependencies:

```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
Clone minilibx repo:
```
$ git clone https://github.com/42Paris/minilibx-linux.git
```
Run the config tool:
```
./configure
```
For more details, check miniLibx repository [`Readme`](https://github.com/42Paris/minilibx-linux).

## Usage

To compile the program, run:

```
$ make
```

Execute the software, providing the name of the fractal set and the seed, when necessary:
```
$ ./fractol Julia -0.73 0.14
```
Avaliable sets:
```
mandelbrot
julia


