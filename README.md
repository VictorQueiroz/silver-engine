# gmagick

### Installation

```
yarn add gmagick
```

### Requirements

- GraphicsMagick 1.3.36
- C++14
- CMake >= 3.7

### Usage

```ts
import {Geometry,Image} from 'gmagick';

const img = new Image();
img.read('image.png');
img.resize(new Geometry(100,100,0,0));
img.write('new-image.png');
```

```ts
import {Image} from 'gmagick';

const img1 = new Image();
img1.read('image.png');

const img2 = new Image();
img2.read('image.png');
img2.motionBlur(20,3,40);

console.log(img2.compare(img1));
```

```ts
import {
    Image,
    Color,
    Geometry
} from 'gmagick';

const img = new Image();
img.density(new Geometry('256x256'));
img.backgroundColor(new Color(0,0,0,0));
img.read(
    path.resolve(__dirname,'icon.svg')
);
img.resize(new Geometry(256,256,0,0));
img.write(__dirname + '/icon.png');
```
