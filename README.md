<h1>Mushroom Evolve</h1>
Nicolas Muras - nicolasmuras@gmail.com -Enero 2021

<h2></h2>

![alt text](https://github.com/NicolasMuras/mushroom_evolve/blob/main/Progress%20in%20pictures/DAY_12B.jpg?raw=true)

<h2><a id="user-content-tabla-de-contenido" class="anchor" aria-hidden="true" href="#tabla-de-contenido"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Tabla de contenido
</h2>
<ul>
  <li><a href="#introduccion-al-proyecto">Introducción al proyecto</a></li>
  <li><a href="#implementaci%C3%B3n-del-proyecto">Implementacion del proyecto</a></li>
  <li><a href="#configuracion-de-teclas">Configuración de teclas</a></li>
</ul>

<h2><a id="user-content-introduccion-al-proyecto" class="anchor" aria-hidden="true" href="#introduccion-al-proyecto"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Introduccion al proyecto</h2>

El objetivo del proyecto era probar las fortalezas de la generacion procedural para crear objetos en 3D, siguiendo un patron similar al ejecutado en este programa, me doy cuenta de que seria no seria dificil crear objetos totalmente diferentes apartir de geometrias basicas.

<h2><a id="user-content-implementación-del-proyecto" class="anchor" aria-hidden="true" href="#implementación-del-proyecto"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Implementación del proyecto</h2>
<ul>
<li><strong>C++</strong>: El lenguaje utilizado para la elaboracion del codigo.</li>
<li><strong>OpenGL</strong>: API utilizada para visualizar nuestros objetos en tiempo real.</li>
<li><strong>SOIL2</strong>: Libreria utilizada para cargar las texturas en el HUD.</li>
<li><strong>GLEW</strong>: Proporciona mecanismos eficientes en tiempo de ejecución para determinar qué extensiones de OpenGL son compatibles con la plataforma de destino.</li>
<li><strong>GLUT</strong>: Utilizamos GLUT para crear nuestras ventanas en el contexto de OpenGL, como asi tambien para propocionar lectura de mouse y teclado.</li>
</ul>

Empece por trabajar el diseño y jerarquias de las clases siguiendo el paradigma de la programación orientada a objetos por un lado y luego pase a trabajar con el core del programa: la clase 'builder' se encarga de construir y devolver el estado del objeto para que asi pueda ser renderizado en tiempo real, utilizando numeros aleatorios y reglas (muy importante) logramos establecer patrones que se asemejan al objeto que queremos crear.

<h2><a id="user-content-configuracion-de-teclas" class="anchor" aria-hidden="true" href="#configuracion-de-teclas"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Configuración de teclas</h2>

<table>
  <tbody><tr>
   <td><strong>Tecla</strong>
   </td>
   <td><strong>Función</strong>
   </td>
  </tr>
  <tr>
   <td><strong>1, 2, 3, 4</strong>
   </td>
   <td><a>Selección de especie / strain.</a>
   </td>
  </tr>
  <tr>
   <td><strong>METHOD</strong>
   </td>
   <td>GET
   </td>
  </tr>
  <tr>
   <td><strong>Details</strong>
   </td>
   <td>Obtener todos los estados en la DB
   </td>
  </tr>
  <tr>
   <td><strong>Request Headers</strong>
   </td>
   <td>-
   </td>
  </tr>
  <tr>
   <td><strong>Request Body</strong>
   </td>
   <td>-
   </td>
  </tr>
  <tr>
   <td><strong>Response Body</strong>
   </td>
   <td>JSON con todos los estados
   </td>
  </tr>
  <tr>
   <td><strong>Response Status</strong>
   </td>
   <td>200
   </td>
  </tr>
</tbody></table>

Keys: 
press '+' to build a shroom.
press 'p' to grow up the shrooms.

Compiled in Visual Studio 2017, x86 bits.

Proyect finished in 13 Days, i really enjoyed it.


