/*******************************************************************/
/**                  +-+-+-+-+-+-+-+-+-+-+                        **/
/**                  |  L P J  -  w s l  |                        **/
/**                  +-+-+-+-+-+-+-+-+-+-+                        **/
/**                                                               **/
/**   i n c l u d e / t r e e . h                                 **/
/*******************************************************************/

#ifndef TREE_H /* Already included? */
#define TREE_H

/* Definition of constants */

#define allom1 100.0
#define allom2 40.0
#define allom3 0.67  /*0.5*/
#define allom4 0.3
#define reinickerp 1.6
#define k_latosa 4e3
#define wooddens 2e5
#define FPC_TREE_MAX 0.95
#define height_max 100.0

/* Declaration of datatypes */

typedef struct
{
  Real leaf,sapwood,root;
}Treephys;

typedef struct
{
  Real leaf,sapwood,heartwood,root,debt;
#ifdef OPTIMUM_ESTAB
  Real old_leaf, old_sapwood, old_heartwood, old_root, old_debt, old_nind;
#endif
}Treephys2;

typedef struct
{
  int leaftype;               /*par16*/
  Treephys turnover;          /*turnover period (years) (9,11,12)*/
  Treephys cn_ratio;          /*C:N mass ratio (13-15) */
  Real crownarea_max;         /*tree maximum crown area (m2) (20)*/
  Treephys2 sapl;             /* sapling */
  Real o3crit;                //OZONE - critical threshold
  Limit o3aparam;             //OZONE - ozone low / high sensitivity parameters
  Real max_wtd;               /*inund_height: max WTP tolerated 37*/
  //  Real allom1;            /*Constant 1 in allometry qeuation, allom1 38*/
  //  Real allom2;            /*Constant 2 in allometry qeuation, allom2 39*/
  //  Real latosa;            /*Leaf to sapwood area ratio (m2 * m-2), latosa 40*/
  //  Real wooddens;          /*Wood density (gC * m-3), wooddens 41*/
  Real maxinunddays;          /*max days of inundation tolerated 42*/
  Real bulkdens;              /*Bulk density (kg biom./m3) from SPITFIRE v1 - what the BD for dead sphagnum is 43*/
  int ispeat;                 /*Peatland PFT (0 not a peatland PFT;1 peatland PFT ) 44*/
  Real pip;                   /* Potential Isoprene Production Is (μg g−1h−1) */
  Real pmp;                   /* Potential Monoterpene Production (μg g−1h−1) */
  Real ms;                    /* Monoterpene storage */
} Pfttreepar;

typedef struct
{
  /*int leafondays,leafoffdays;
  Bool leafon;*/
  Real height;
  Real crownarea;
  Real gddtw;
  Real aphen_raingreen;
  Treephys2 ind;
} Pfttree;

/* Declaration of functions */

extern void new_tree(Pft *);
extern Pft *newpftage(Pftpar *,int);
extern Real npp_tree(Pft *,Real,Real,Real,Bool *,Real, Real *); 
extern void mortality_tree(Litter *,Pft *,Real,Real,Real *);
extern Real fpc_tree(Pft *);
extern Real fpar_tree(Pft *);
extern Real litter_update_tree(Litter *, Pft *,Real,Real *,Bool,Bool);
extern void allometry_tree(Pft *pft);
extern void allocation_tree(Litter *,Pft *,Real *,Bool);
extern Real lai_tree(const Pft *);
extern Real turnover_tree(Litter *,Pft *);
extern Bool phenology_tree(Pft *,int,Real,Real,Real[],int,Real,Bool,int,Real,Real); 
extern Bool fwrite_tree(FILE *,const Pft *);
extern void fprint_tree(FILE *,const Pft *);
extern void fread_tree(FILE *,Pft *,Bool);
extern Bool fscanpft_tree(FILE *,Pftpar *,const char *);
extern Bool isneg_tree(const Pft *);
extern Real establishment_tree(Pft *,Real,Real,int);
extern void reproduction_tree(Litter *,Pft *);
extern void init_tree(Pft *);
extern Real fire_tree(Pft *,Real *);
extern Real vegc_sum_tree(const Pft *);
extern void mix_veg_tree(Pft *,Real);
extern void free_tree(Pft *);
extern void light_tree(Litter *,Pft *,Real,Bool);
extern void adjust_tree(Litter *,Pft *,Real,Bool);

/* Definitions of macros */

#define istree(pft) (getpftpar(pft,type)==TREE)
#define israingreen(pft) getpftpar(pft,phenology)==RAINGREEN
#define fprinttreephys2(file,phys,nind) fprintf(file,"%6.2f %6.2f %6.2f %6.2f %6.2f",phys.leaf*nind,phys.sapwood*nind,phys.heartwood*nind,phys.root*nind,phys.debt*nind)
#define phys_sum_tree(ind) (ind.leaf+ind.root+ind.heartwood+ind.sapwood)

#endif
