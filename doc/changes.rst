.. _changes:

Changelog
=========

Changes in version (future)
---------------------------

* Validate order of boundaries for input tesseroids. Errors if boundaries are
  switched (e.g, W > E).
  (`PR 27 <https://github.com/leouieda/tesseroids/pull/27>`__)
* Ignore tesseroids with zero volume from the input file (i.e., W == E, S == N,
  or top == bottom). These elements can cause crashes because of infinite loops
  during adaptive discretization.
  (`PR 27 <https://github.com/leouieda/tesseroids/pull/27>`__)

Changes in version 1.2.0
------------------------

* General improvements to the adaptive discretization (described in the
  upcoming method paper).
  (`PR 21 <https://github.com/leouieda/tesseroids/pull/21>`__)
* Better error messages when there is a stack overflow (computation point too
  close to the tesseroid).
  (`PR 21 <https://github.com/leouieda/tesseroids/pull/21>`__)
* Replace the recursive algorithm with a stack-based algorithm for adaptive
  discretization of tesseroids. This makes the computations faster, specially
  for gravity acceleration and gradient tensor components.
  (`PR 21 <https://github.com/leouieda/tesseroids/pull/21>`__)
* Divide the tesseroids only along the necessary dimensions. This provides
  speedups when dealing with flattened or elongated tesseroids.
  (`PR 21 <https://github.com/leouieda/tesseroids/pull/21>`__)
* Speedup tesseroid computations by moving some trigonometric functions out of
  loops.
  (`PR 22 <https://github.com/leouieda/tesseroids/pull/22>`__)
* BUG fix: Singularities when calculating around a prism. Due to wrong quadrant
  returned by atan2 and log(0) evaluations. Fix by wrapping atan2 in a
  safe_atan2 that corrects the result. log(0) error happened only in cross
  components of the gravity gradient when the computation is aligned with the
  vertices of a certain face (varies for each component. Fix by displacing the
  point a small amount when that happens.
  (`PR 12 <https://github.com/leouieda/tesseroids/pull/12>`__)

Changes in version 1.1.1
------------------------

* BUG fix: Wrong results when calculating fields below a prism in Cartesian
  coordinates (`PR 1 <https://github.com/leouieda/tesseroids/pull/1>`__)

Changes in version 1.1
----------------------

* the tesseroids license was changed from the GNU GPL
  to the more permissive BSD license
  (see :ref:`the license text <license>`).
* tess2prism has a new flag --flatten
  to make the prism model by flattening the tesseroids
  (i.e., 1 degree = 111km) into Cartesian coordinates
  (so that they can be used with the prismg* programs).
* tessg* programs have a new flag -t
  used to control the distance-size ratio for the automatic recursive division
  of tesseroids.
* **NEW PROGRAMS** prismpots, prismgs, and prismggts,
  to calculate the prism effects
  in spherical coordinates.
  These programs are compatible with the output of tess2prism
  (see :ref:`this recipe <recipe_tess2prism>` for an example).
* **NEW PROGRAM** tesslayers to generate a tesseroid model of a stack of layers
  from grids of the thickness and density of each layer.
  tesslayers complements the functionality of tessmodgen
  and can be used to generate crustal models,
  sedimentary basin models, etc.
  (see :ref:`this recipe <recipe_tesslayers>` for an example).
* tesseroids now strictly follows the ANSI C standard.
* Bug fix: prismpot, prismgx, prismgy, prismgz, and prismgxy had problems with
  a log(z + r) when the computation point was bellow the top of the prism
  (zp > prism.z1). Fixed by calculating on top of the prism when this happens,
  then changing the sign of the result when needed (only for gz).
* Bug fix: the tessg and prismg family of programs was crashing when the model
  file is empty. Now they fail with an error message.


Changes in version 1.0
----------------------

Tesseroids 1.0 was completely re-coded in the C programming language
and is much faster and more stable than the 0.3 release.
Here is a list of new features:

* tesspot and tessg* programs now take the computation points as input,
  allowing for custom grids.
* tesspot and tessg* programs now automatically subdivide a tesseroid
  if needed to maintain GLQ precision
  (this makes computations up to 5x faster and safer).
* Automated model generation using program tessmodgen.
* Regular grid generation with program tessgrd.
* Total mass calculation with program tessmass.
* Programs to calculate the gravitational fields
  of right rectangular prisms in Cartesian coordinates.
* HTML User Manual and API Reference generated with Doxygen.
* Easy source code compilation with SCons.
