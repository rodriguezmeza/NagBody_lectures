# Interpolation code



Mario Alberto Rodriguez-Meza (ININ, Mexico), 
marioalberto.rodriguez@inin.gob.mx

#


interpolation is a C code that computes interpolation of power spectrum table. 

Specifically, it computes:

- matter power spectrum extended from kmin to kmax

The code units are Mpc/h. 

The power spectrum convention is 
(2pi)^3 delta_D(k+k') P(k) = <delta(k) delta(k')> 



## Run

DOWNLOAD:

Git clone

```
git clone https://github.com/rodriguezmeza/NagBody_lectures.git
```

or download it from http://www.github.com/rodriguezmeza/NagBody_lectures.git


Compile:

```
/interpolation/src$ make
```

Run: in the parent directory

```
/interpolation$ ./interpolation
```
This will read the power spectrum table from Input dir and extend it.

For help:

```
/interpolation$ ./interpolation -help
```


In help you can see how to change parameters, in the form [option]=[value], for example:

```
/interpolation$ ./interpolation kmin=0.001 kmax=0.1
```


Alternatively you can run the code with a parameters file:

```
/interpolation$ ./interpolation parameters.in
```


The input of the code is the LCDM linear power spectrum extrapolated to present time with two columns 

| column  | function  |
| ------------: |:---------------| 
| #1            | k   (in h/Mpc)|
| #2            | P_L   (in (h/Mpc)^3)        |  




By default it is located in /interpolation/Input/psLCDM.in


The code gives a file as output: 

## output PSL.dat 

with structure


| column  | function  |
| ------------: |:---------------| 
| #1            | k   |
| #2            | PSL   (linear extended power spectrum)        |  


```
/interpolation$ ./mgpt Nk=100 kmin=0.001 kmax=0.2
```

so the output will contain 100 k-points equally spaced in log intervals, from k=0.001 to kmax=0.2 h/Mpc. 


## Modifying the code

The file interpolation/scr/interpol.c is where the user can modified to make different computation on the power spectrum.

```
/interpolation$ cd src
/interpolation/src$ make clean
/interpolation/src$ make
/interpolation/src$ cd ..
```
If you find problems with this, feel free to contact us.


## References

If you use this code please cite the following paper:

2. Alejandro Aviles, Mario Alberto Rodriguez-Meza, Josue De-Santiago, and Jorge-Luis Cervantes-Cota [JCAP 11 (2018) 013] https://arxiv.org/abs/1809.07713



