# ketvirta_uzduotis-vektorius-

## Mano ir std::vektoriaus palyginimas

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

## Vektoriaus funkcijos

### size():
```
size_type size() const { return avail - data; }
```
### capacity():
```
size_type capacity() const { return limit - data; }
```
## Iteratoriai

### begin():
```
iterator begin() { return data; }
const_iterator begin() const { return data; }
```
### end():
```
iterator end() { return avail; }
const_iterator end() const { return avail; }
```
### rbegin():
*Returns a reverse iterator to the first element of the reversed container.
*It corresponds to the last element of the non-reversed container.
*If the container is empty, the returned iterator is equal to rend().

```
iterator rbegin()
 {
      iterator it = limit;
      return --it;
 }
const_iterator rbegin() const
 {
      iterator it = limit;
      return --it;
 }
```
### rend():
```
iterator rend()
 {
     iterator it = data;
     return ++it;
 }
 const_iterator rend() const
 {
     iterator it = data;
     return ++it;
 }
```
### push_back():
```
void push_back(const T& val)
{
    if (avail == limit)
    {
      grow();
    }
      unchecked_append(val);
}
```
#### Pridedu grow() funkciją:
```
void grow()
    {
        size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);

        uncreate();

        data = new_data;
        avail = new_avail;
        limit = data + new_size;
    }
```
#### Pridedu unchecked_append() funkciją:
```
void unchecked_append(const T& val)
    {
        alloc.construct(avail++, val);
    }
```
