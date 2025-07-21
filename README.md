# 📖 "Movilidad Inteligente: Un Enfoque Integral en la Matriculación Vehicular"
Programa en C que te permite registrar información vehicular y calcular el valor de su matrícula.

---

## Integrantes 👥
Poryecto desarrollado por:
* **Cristopher Chamorro** _Rol: Tester_ - [@]()
* **David Pesantez** _Rol: Jefe de proyecto_ - [@]()
* **Erick Puglla** _Rol: Desarrollador_ - [@]()

---

## **Descripción del Proyecto**📝

* El programa creado puede registrar información vehicular básica y en base a ello calcular el valor de matrícula y guardar su información. Esto en respuesta a los conocimientos de nuestro grupo que adquirimos durante el transcurso del semestre.
* Permite registrar un usuario y contraseña para acceder a un menú, sin ello no tendra acceso a las demás funciones, dentro del menú puede registrar información como placa, año, tipo de vehículo y su avaluo; calcular matrícula en base a impuestos establecidos en Ecuador y guardar el recibo a pagar con los datos vehiculares en los archivos `datosVehiculares.txt`, `datosVehicularesMatriculacion.txt` y los usuarios en `usuario.txt` .
* En la parte de desarrollo se aplico estructuras selectivas y repetitivas: `if-else`, `switch`, `for`, `do-while`. Además, se implementaron estructuras definidas y una variable global para el conteo de vehículos registrados.

---

## **Tutorial para Compilar y Ejecutar** ⚙️
Para que puedas probrar nuestro código desde una terminal te dejamos los pasos a seguir. Te recordamos que debes tener un compilador de C.

1. **Clonar el repositorio**
```bash
git clone [https://github.com/Cristopherch/Proyecto-Matriculaci-n-Vehicular.git](https://github.com/Cristopherch/Proyecto-Matriculaci-n-Vehicular.git)
```
2. **Navegar a la carpeta del proyecto**
```bash
cd Proyecto-Matriculaci-n-Vehicular
```
3. **Compilar el código**
```bash
gcc mains.c mivehiculo.c matricular.c validaciones.c
```
4. **Ejecutar el programa**
```bash
./registro_vehicular
```
---

### 💡 Alternativa usando Zinjai (IDE)
> Puedes usar [Zinjai](https://zinjai.sourceforge.net/) para compilar y ejecutar el código.
* Sigue estos pasos:
1. Abre Zinjai.
2. Ve a `Archivo` → `Nuevo Proyecto` y selecciona las cabeceras y fuentes, asegurate de incluir el `main.c`
3. Presiona en el boton **compilar** y luego en **ejecutar**

---

## **Limitantes**
* El programa solo admite un máximo de 100 vehículos
* Se deben respetar los formatos de datos que se ingresa para el registro vehicular, cálculo de matrícula y guardado de datos

---

## **Estructura de Archivos** 📂

A continuación se explica brevemente los archivos que forman parte del código:

```
.
├──mains.c                  # Archivo donde se llama a todas las funciones y que contiene el menú del usuario.
├──mivehiculo.c
├──matricular.c             # Archivos que contienen el desarrollo de las funciones para registro de vehículos, cálculo de matrícula, guardado de de 
├──validacion.c              información y verficación que los datos de enetrada esten con el formato correcto.
├──mivehiculo.h
├──matricular.h             # Archivos de cabecera donde se declararon las funciones.
├──validaciones.h
├──README

```
---

## **Información del curso** 🏫
* **Asignatura:** Programación I
* **Docente:** Nelson Herrera
* **Semestre:** Primer Semestre
* **Universidad:** Escuela Politécnia Nacional
