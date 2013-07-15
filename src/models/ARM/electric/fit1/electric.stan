data {
  int<lower=0> N1; 
  int<lower=0> N2; 
  int<lower=0> N3; 
  int<lower=0> N4; 
  vector[N1] post_test1;
  vector[N2] post_test2;
  vector[N3] post_test3;
  vector[N4] post_test4;
  vector[N1] treatment1;
  vector[N2] treatment2;
  vector[N3] treatment3;
  vector[N4] treatment4;
}
parameters {
  vector[2] beta1;
  vector[2] beta2;
  vector[2] beta3;
  vector[2] beta4;
  real<lower=0> sigma1;
  real<lower=0> sigma2;
  real<lower=0> sigma3;
  real<lower=0> sigma4;
} 
model {
  post_test1 ~ normal(beta1[1] + beta1[2] * treatment1,sigma1);
  post_test2 ~ normal(beta2[1] + beta2[2] * treatment2,sigma2);
  post_test3 ~ normal(beta3[1] + beta3[2] * treatment3,sigma3);
  post_test4 ~ normal(beta4[1] + beta4[2] * treatment4,sigma4);
}