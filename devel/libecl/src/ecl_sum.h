#ifndef __ECL_SUM_H__
#define __ECL_SUM_H__

#include <stdbool.h>
#include <hash.h>

typedef struct ecl_sum_struct ecl_sum_type;
typedef enum {ecl_sum_well_var , ecl_sum_region_var , ecl_sum_field_var , ecl_sum_group_var , ecl_sum_misc_var , ecl_sum_completion_var , ecl_sum_NOT_IMPLEMENTED_var} ecl_sum_var_type;

void             ecl_sum_fread_alloc_data(ecl_sum_type * , int , const char ** , bool);
ecl_sum_type   * ecl_sum_fread_alloc(const char * , int , const char **, bool  , bool );
ecl_sum_var_type ecl_sum_iget_var_type(const ecl_sum_type * , int );
int            	 ecl_sum_get_Nwells(const ecl_sum_type *);
void           	 ecl_sum_copy_well_names(const ecl_sum_type * , char **);
void           	 ecl_sum_init_save(ecl_sum_type * , const char * , int , bool);
bool           	 ecl_sum_has_well_var(const ecl_sum_type * , const char * , const char *);
bool           	 ecl_sum_has_var(const ecl_sum_type * , const char *);


int            	 ecl_sum_get_well_var_index(const ecl_sum_type * , const char * , const char *);
int            	 ecl_sum_get_region_var_index(const ecl_sum_type * , int , const char *);
int              ecl_sum_get_group_var_index(const ecl_sum_type * , const char * , const char *);
int              ecl_sum_get_field_var_index(const ecl_sum_type * , const char *);
int              ecl_sum_get_well_completion_var_index(const ecl_sum_type * , const char * , const char * , int );
double         	 ecl_sum_get_well_var(const ecl_sum_type *, int , const char *, const char *);
double         	 ecl_sum_get_group_var(const ecl_sum_type *, int , const char *, const char *);
double         	 ecl_sum_get_region_var(const ecl_sum_type *, int , int , const char *);
double         	 ecl_sum_get_field_var(const ecl_sum_type *,  int , const char *);
double         	 ecl_sum_get_with_index(const ecl_sum_type *, int , int);
double         	 ecl_sum_iget_with_index(const ecl_sum_type *, int , int);
double           ecl_sum_get_well_completion_var(const ecl_sum_type * , int , const char * , const char * , int );

void           	 ecl_sum_free_data(ecl_sum_type * );
void           	 ecl_sum_free(ecl_sum_type *);
int            	 ecl_sum_get_size(const ecl_sum_type *);
void           	 ecl_sum_set_fmt_mode(ecl_sum_type *, int );
void           	 ecl_sum_save(const ecl_sum_type * );
void           	 ecl_sum_set_header_data(ecl_sum_type * , const char * , void *);
char        ** 	 ecl_sum_alloc_well_names_copy(const ecl_sum_type *);
const  char ** 	 ecl_sum_get_well_names_ref(const ecl_sum_type * );
char          ** ecl_sum_alloc_group_names(const ecl_sum_type * );
bool           	 ecl_sum_get_report_mode(const ecl_sum_type * );
time_t         	 ecl_sum_get_start_time(const ecl_sum_type * );
time_t         	 ecl_sum_iget_sim_time(const ecl_sum_type * , int );
time_t         	 ecl_sum_get_sim_time(const ecl_sum_type * , int );
const   char * 	 ecl_sum_get_unit_ref(const ecl_sum_type *  , const char *);
int            	 ecl_sum_get_report_size(const ecl_sum_type * , int * , int * );

int 		 ecl_sum_get_num_groups(const ecl_sum_type * ecl_sum);
int 		 ecl_sum_get_num_regions(const ecl_sum_type * ecl_sum);

void           	 ecl_sum_max_min(const ecl_sum_type * , int , const char ** , int , const char ** , double *, double *, bool);
void           	 ecl_sum_well_max_min(const ecl_sum_type * , const char * , int  , const char **  , double *, double * , bool);
double         	 ecl_sum_eval_well_misfit(const ecl_sum_type * , const char * , int , const char ** , const double * );
double         	 ecl_sum_eval_misfit(const ecl_sum_type * , int , const char ** , int , const char ** ,  const double * , double * );
ecl_sum_type * 	 ecl_sum_fread_alloc_interactive(bool );
void             ecl_sum_fprintf(const ecl_sum_type * , FILE * , int , int , const char **  , const char ** );
#endif
