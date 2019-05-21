# ketvirta_uzduotis-vektorius-

## Mano ir std vektoriaus palyginimas

### Su mano vektoriumi:

| ***10000 eilučių***   | ***0.217268 s.*** |
| :------------- | :----------: | 
| ***100000 eilučių*** | ***1.9626 s.*** |
| ***1000000 eilučių***   | ***25.9509 s.*** |
| ***10000000 eilučių***   | ***234.638 s.***|

*silpnų skaičius (4132833) + gerų skaičius (5867171) = 10 000 004 (dėl to, kad ir viename ir kitame faile pirmos 2 eilutės yra tekstinės)

### Su std::vector:

| ***10000 eilučių***   | ***0.299623 s.*** |
| :------------- | :----------: | 
| ***100000 eilučių*** | ***2.12425 s.*** |
| ***1000000 eilučių***   | ***30.4396 s.*** |
| ***10000000 eilučių***   | ***287.94 s.***|

*silpnų skaičius (4134227) + gerų skaičius (5865777) = 10 000 004 (dėl to, kad ir viename ir kitame faile pirmos 2 eilutės yra tekstinės)
