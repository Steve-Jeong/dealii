//-------------------------------------------------------------------------
//    $Id$
//    Version: $Name$
//
//    Copyright (C) 2005, 2006 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//-------------------------------------------------------------------------

/**
 * @defgroup Quadrature Quadrature formul�
 *
 * This module contains the base class Quadrature as well as the quadrature
 * formul� provided by deal.II. Quadrature formulas provide two essential
 * pieces of data: the locations of quadrature points on the unit cell
 * [0,1]^d, and the weight of each quadrature point.
 *
 * Since deal.II uses quadrilaterals and hexahedra, almost all quadrature
 * formulas are generated as tensor products of 1-dimensional quadrature
 * formulas defined on the unit interval [0,1], which makes their definition
 * for the higher-dimensional case almost trivial. However, the library also
 * allows anisotropic tensor products (more quadrature points in one
 * coordinate direction than in another) through the QAnisotropic class, as
 * well as the definition of quadrature formulas that are not tensor products.
 *
 * 
 * <h3>Use</h3>
 * 
 * Quadrature formulas are used, among other uses, when integrating matrix
 * entries and the components of the right hand side vector. To this end, the
 * quadrature point defined on the unit cell have to be mapped to the
 * respective locations on a real cell, and the weights have to be multiplied
 * by the determinant of the Jacobian. This step is done by classes derived
 * from the Mapping base class, although this is often hidden since many parts
 * of the library fall back to using an object of type MappingQ1 if no
 * particular mapping is provided.
 *
 * The next step is to evaluate shape functions and their gradients at these
 * locations. While the classes derived from the FiniteElement base class
 * provide a description of the shape functions on the unit cell, the actual
 * evaluation at quadrature points and joining this with the information
 * gotten from the mapping is done by the FEValues class and its
 * associates. In essence, the FEValues class is therefore a view to the
 * finite element space (defined by the FiniteElement classes) evaluated at
 * quadrature points (provided by the Quadrature classes) mapped to locations
 * inside cells in real, as opposed to unit, space (with the mapping provided
 * by the Mapping classes).
 *
 * The FEValues class provides, as a side product, the location of the
 * quadrature points as mapped to a real cell, for other uses as well. This
 * can then be used, for example, to evaluate a right hand side function at
 * these points.
 * 
 *
 * <h3>QIterated</h3>
 * 
 * The class QIterated is used to construct an iterated quadrature formula out
 * of an existing one, thereby increasing the accuracy of the formula without
 * increasing the order. For example, by iterating the trapezoidal rule with
 * points at 0 and 1 and weights 1/2 and 1/2 twice, we get a quadrature
 * formula with points at 0, 1/2, and 1 with weights 1/4, 1/2, and 1/4,
 * respectively. This formula is obtained by projecting the quadrature formula
 * onto the subintervals [0,1/2] and [1/2,1], respectively, and then merging
 * the right endpoint of the left interval with the left endpoint of the right
 * interval. In the same way, all one-dimensional quadrature formulas can be
 * iterated. Higher dimensional iterated formulas are generated as tensor
 * products of one-dimensional iterated formulas.
 *
 *
 * <h3>QAnisotropic</h3>
 *
 * While the usual quadrature formul� of higher dimensions
 * generate tensor products which are equal in each direction, the
 * class QAnisotropic generates tensor products of possibly different
 * formul� in each direction.
 *
 *
 * <h3>QProjector</h3>
 *
 * The class QProjector is not actually a quadrature rule by itself,
 * but it provides functions for computing quadrature formulas on the
 * surfaces of higher dimensional cells.
 *
 * All other classes in this module actually implement quadrature
 * rules of different order and other characteristics.
 */

/**
 * @defgroup IO Input/Output
 *
 * This module collects the classes used for reading and writing
 * meshes and data.
 *
 * The list of supported formats can be found in the
 * description of the classes
 * <ul>
 * <li> GridIn for reading meshes,
 * <li> GridOut for writing meshes,
 * <li> DataOutBase for writing simulation results.
 * </ul>
 *
 * For writing data, you would normally use objects of the class
 * DataOut (DataOutBase only provides the low level output
 * functions). Still, there are some other options for more
 * specialized needs, like DataOutFaces, DataOutRotation and
 * DataOutStack.
 */

/**
 * @defgroup Polynomials Polynomials and polynomial spaces
 */
